/*
** pile_larg.c for pile in /home/duhieu_b/IA/dante/largeur
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Apr 27 19:32:02 2016 benjamin duhieu
** Last update Wed Apr 27 19:54:03 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "pars.h"
#include "larg.h"

int		add_elem_pile(t_case *cas, t_link *root, t_case *prev)
{
  t_link	*new;

  if (!(new = malloc(sizeof(t_link))))
    return (1);
  new->next = root;
  new->prev = root->prev;
  root->prev->next = new;
  root->prev = new;
  new->cas = cas;
  new->cas->back = prev;
  return (0);
}

void		change_graph(t_case *last)
{
  t_case	*elem;

  elem = last;
  while (elem)
    {
      elem->path = 1;
      elem = elem->back;
    }
}

int		join_elem_to_pile(t_link *cur, t_link *pile)
{
  t_link	*elem;

  cur->cas->path = -1;
  elem = cur->cas->link;
  while (elem)
    {
      if (elem->cas->path == -1)
	{
	  elem = elem->next;
	  continue;
	}
      else
	{
	  if (add_elem_pile(elem->cas, pile, cur->cas))
	    return (1);
	  if (elem->cas->end)
	      return (2);
	  elem = elem->next;
	}
    }
  return (0);
}
