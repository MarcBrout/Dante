/*
** solver.c for dante in /home/brout_m/RENDU/CPE/dante/profondeur
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Apr 19 11:08:26 2016 marc brout
** Last update Wed Apr 27 19:27:06 2016 marc brout
*/

#include <unistd.h>
#include "my.h"
#include "profondeur.h"

char		check_loop(t_case *cas)
{
  t_link	*cur;
  int		total;

  cur = cas->link;
  total = 0;
  while (cur)
    {
      if (cur->cas->path)
	++total;
      cur = cur->next;
    }
  return ((total > 1) ? 1 : 0);
}

int		write_graph(t_case *root, int width)
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

int		solve_by_length(t_case *root, int width)
{
  int		ret;

  if ((ret = launch_solve_by_length(root)) == 1)
    return (1);
  else if (ret == 2)
    return (my_put_error(NO_PATH), 0);
  return (write_graph(root, width));
}

int		main(int ac, char **av)
{
  t_pars	*parser;

  if (ac < 2)
    return (my_put_error(USAGE), 1);
  if (!(parser = recup_graph(av[1])))
    return (1);
  if (!solve_by_length(parser->cas, parser->width))
    {
      free_graph(parser);
      return (0);
    }
  free(parser);
  return (1);
}
