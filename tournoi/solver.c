/*
** solver.c for dante in /home/brout_m/RENDU/CPE/dante/profondeur
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Apr 19 11:08:26 2016 marc brout
** Last update Thu Apr 28 00:23:51 2016 marc brout
*/

#include <unistd.h>
#include "my.h"
#include "tournoi.h"

static int	write_graph(t_case *root, int width)
{
  t_case	*cur;
  int		i;

  cur = root;
  i = 0;
  while ((cur = cur->next) && cur != root && ++i >= 0)
    {
      if (!cur->pass && cur->path == 1)
	{
	  if (write(1, "o", 1) < 1)
	    return (1);
	}
      else if (!cur->pass)
	{
	  if (write(1, "*", 1) < 1)
	    return (1);
	}
      else
	if (write(1, "X", 1) < 1)
	  return (1);
      if (i && !(i % (width + 1)))
	if (write(1, "\n", 1) < 1)
	  return (1);
    }
  return (0);
}

static void	roll_back_laby(t_case *root)
{
  t_case	*cur;

  cur = root->prev;
  root->next->path = 1;
  while (cur != root->next)
    {
      cur->path = 1;
      cur = cur->back;
    }
}

static int	solve_by_tournoi(t_case *root, int width)
{
  int		ret;

  if ((ret = launch_solve_by_tournoi(root)) == 1)
    return (1);
  else if (ret == 2)
    return (my_put_error(NO_PATH), 0);
  roll_back_laby(root);
  return (write_graph(root, width));
}

int		main(int ac, char **av)
{
  t_pars	*parser;

  if (ac < 2)
    return (my_put_error(USAGE), 1);
  if (!(parser = recup_graph(av[1])))
    return (1);
  if (!solve_by_tournoi(parser->cas, parser->width))
    {
      free_graph(parser);
      return (0);
    }
  free(parser);
  return (1);
}
