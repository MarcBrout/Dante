/*
** solver.c for dante in /home/brout_m/RENDU/CPE/dante/profondeur
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Apr 19 11:08:26 2016 marc brout
** Last update Fri Apr 22 12:52:04 2016 marc brout
*/

#include "my.h"
#include "parser.h"
#include "longueur.h"

int		add_this_link(t_link **last, t_link *link)
{
  if (!(*last->next = malloc(sizeof(t_link))))
    return (my_put_error(MALLOC_ERR), 1);
  *last->next->cas = link->cas;
  *last->next->next = NULL;
  *last->next->prev = *last;
  *last = last->next;
  return (0);
}

int		add_to_pile(char *go_back, t_link **last)
{
  t_link	*link;
  int		total;

  total = 0;
  link = *last->cas->link;
  while (link)
    {
      if (!link->cas->path && !link->cas->pass)
	{
	  if (add_this_link(last, link))
	    return (1);
	  ++total;
	}
      link = link->next;
    }
  *go_back = (total) ? 0 : 1;
  return (0);
}

void		remove_from_pile(t_link **last)
{
  *last->cas->path = -1;
  if (*last->prev)
    {
      *last = *last->prev;
      free(*last->next);
      *last->next = NULL;
    }
  else
    {
      free(*last);
      *last = NULL;
    }
}

t_link		*init_pile_root(t_case *first)
{
  t_link	*root;

  if (!(root = malloc(sizeof(t_link))))
    return (my_put_error(MALLOC_ERR), NULL);
  root->cas = first;
  root->next = NULL;
  root->prev = NULL;
  first->path = 1;
  return (root);
}

int		launch_solve_by_lenght(t_case *first)
{
  t_link	*last;
  char		go_back;

  if (!(last = init_pile_root(first->next)))
    return (1);
  go_back = 0;
  while (last)
    {
      last->cas->path = 1;
      if (last->cas->next == first)
	return (0);
      if (add_to_pile(&go_back, &last))
	return (1);
      if (go_back)
	{
	  remove_from_pile(&last);
	  go_back = 0;
	}
    }
  return (2);
}

void		write_graph(t_case *first, int width)
{
  t_case	*cur;
  int		i;

  cur = first;
  i = 0;
  while (cur)
    {
      if (!cur->pass && cur->path)
	write(1, "o", 1);
      else if (!cur->pass)
	write(1, "*", 1);
      else
	write(1, "X", 1);
      if (i && !(i % width))
	write(1, "\n", 1);
      cur = cur->next;
      ++i;
    }
}

int		solve_by_lenght(t_case *first, int width)
{
  int		ret;

  if ((ret = launch_solve_by_lenght(first)) == 1)
    return (1);
  else if (ret == 2)
    return (my_put_error(NO_PATH, 0));
  write_graph(first, width);
  return (0);
}
