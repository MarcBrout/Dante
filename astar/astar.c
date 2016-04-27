/*
** astar.c for astar in /home/brout_m/RENDU/CPE/dante
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 27 18:39:45 2016 marc brout
** Last update Wed Apr 27 22:28:23 2016 marc brout
*/

#include <unistd.h>
#include "astar.h"

t_link		*init_list_root()
{
  t_link	*root;

  if (!(root = malloc(sizeof(t_link))))
    return (my_put_error(MALLOC_ERR), NULL);
  root->next = root;
  root->prev = root;
  return (root);
}

int		add_in_closed_list(t_link *root_list, t_link *link)
{
  t_link	*copy;

  if (!(copy = malloc(t_link)))
    return (my_put_error(MALLOC_ERR), 1);
  copy->cas = link->cas;
  copy->prev = root_list;
  copy->next = root_list->next;
  root_list->next->prev = copy;
  root_list->next = copy;
  return (0);
}

int		add_in_open_list(t_link *root_list, t_link *link)
{
  t_link	*copy;
  t_link	*cur;

  if (!(copy = malloc(t_link)))
    return (my_put_error(MALLOC_ERR), 1);
  copy->cas = link->cas;
  cur = root_list->next;
  while (cur != root_list)
    {
      if (cur->t_cost > link->cas->t_cost)
	break;
      cur = cur->next;
    }
  copy->next = cur;
  copy->prev = cur->prev;
  cur->prev->next = copy;
  cur->prev = copy;
  return (0);
}

int		is_in_list(t_link *root_list, t_link *link)
{
  t_link	*cur;

  cur = root_list;
  while ((cur = root_list->next) != root_list)
    {
      if (cur->cas = link->cas)
	return (1);
    }
  return (0);
}

int		add_all_link_to_lists(t_link *open_l, t_link *closed_l,
				      t_case *cas)
{
  t_link	*link;

  link = cas->link;
  while (link)
    {
      if (!is_in_list(closed_l, link))
	{
	  //calcul du cout
	  if (is_in_list(open_l, link))
	    //si cout meileur MAJ + changer parent + tri de la list
	  else
	    add_in_open_list(open_l, link);
	}
      link = link->next;
    }
  return (0);
}

t_link		*pop_from_open_to_closed(t_link *open_l,
					 t_link *closed_l);
{
  t_link	*link;

  link = open_l->next;
  open_l->next = open_l->next->next;
  open_l->next->prev = open_l;
  link->prev = closed_l;
  link->next = closed_l->next;
  closed_l->next->prev = link;
  closed_l->next = link;
  return (link);
}

int		launch_solve_by_astar(t_case *root)
{
  t_link	*open_l;
  t_link	*closed_l;

  if (!(open_l = init_list_root() || !(closed_l = init_list_root())))
    return (1);
  return (1);
}
