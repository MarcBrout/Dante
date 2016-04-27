/*
** resolution.c for dante in /home/brout_m/RENDU/CPE/dante/profondeur
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 27 15:48:41 2016 marc brout
** Last update Wed Apr 27 16:14:31 2016 marc brout
*/

#include <unistd.h>
#include "my.h"
#include "profondeur.h"

int		add_this_link(t_link **last, t_link *link)
{
  if (!((*last)->next = malloc(sizeof(t_link))))
    return (my_put_error(MALLOC_ERR), 1);
  (*last)->next->cas = link->cas;
  (*last)->next->next = NULL;
  (*last)->next->prev = *last;
  *last = (*last)->next;
  return (0);
}

int		add_to_pile(char *go_back, t_link **last)
{
  t_link	*link;
  int		total;

  total = 0;
  link = (*last)->cas->link;
  while (link)
    {
      if (!link->cas->path && !check_loop(link->cas))
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
  (*last)->cas->path = -1;
  if ((*last)->prev)
    {
      *last = (*last)->prev;
      free((*last)->next);
      (*last)->next = NULL;
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

int		launch_solve_by_length(t_case *root)
{
  t_link	*last;
  t_link	*root_pile;
  char		go_back;

  if (!(last = init_pile_root(root->next)))
    return (1);
  root_pile = last;
  go_back = 0;
  while (last)
    {
      last->cas->path = 1;
      if (last->cas->next == root)
	return (free_pile(root_pile), 0);
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
