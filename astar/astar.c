/*
** astar.c for astar in /home/brout_m/RENDU/CPE/dante
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 27 18:39:45 2016 marc brout
** Last update Wed Apr 27 23:58:22 2016 marc brout
*/

#include <stdlib.h>
#include "my.h"
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

int		add_in_open_list(t_link *root_list, t_link *link)
{
  t_link	*copy;
  t_link	*cur;

  if (!(copy = malloc(sizeof(t_link))))
    return (my_put_error(MALLOC_ERR), 1);
  copy->cas = link->cas;
  cur = root_list->next;
  while (cur != root_list)
    {
      if (cur->cas->pos.t_cost > link->cas->pos.t_cost)
	break;
      cur = cur->next;
    }
  copy->next = cur;
  copy->prev = cur->prev;
  cur->prev->next = copy;
  cur->prev = copy;
  return (0);
}

t_link		*is_in_list(t_link *root_list, t_link *link)
{
  t_link	*cur;

  cur = root_list;
  while ((cur = cur->next) != root_list)
    {
      if (cur->cas == link->cas)
	return (cur);
    }
  return (NULL);
}

void		update_link(t_link *open_l, t_link *update)
{
  t_link	*cur;
  t_link	*to_move;

  to_move = is_in_list(open_l, update);
  if (to_move->next->cas->pos.t_cost < to_move->cas->pos.t_cost ||
      to_move->prev->cas->pos.t_cost > to_move->cas->pos.t_cost)
    {
      to_move->prev->next = to_move->next;
      to_move->next->prev = to_move->prev;
      cur = open_l->next;
      while (cur != open_l)
	{
	  if (to_move->cas->pos.t_cost > cur->cas->pos.t_cost)
	    break;
	  cur = cur->next;
	}
      to_move->next = cur;
      to_move->prev = cur->prev;
      cur->prev->next = to_move;
      cur->prev = to_move;
    }
}

int		add_all_link_to_lists(t_case *root,
				      t_link *open_l,
				      t_link *closed_l,
				      t_case *cas)
{
  t_link	*link;
  int		ret;

  link = cas->link;
  while (link)
    {
      if (!is_in_list(closed_l, link))
	{
	  if ((ret = calc_dist(root->prev, cas, link->cas)) == 1)
	    update_link(open_l, link);
	  else if (!ret)
	    if (add_in_open_list(open_l, link))
	      return (1);
	}
      link = link->next;
    }
  return (0);
}

t_link		*pop_from_open_to_closed(t_link *open_l,
					 t_link *closed_l)
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
  t_link	*cur;

  if (!(open_l = init_list_root()) || !(closed_l = init_list_root()))
    return (1);
  if (add_all_link_to_lists(root, open_l, closed_l, root->next))
    return (1);
  root->next->back = root;
  while (open_l->next)
    {
      cur = pop_from_open_to_closed(open_l, closed_l);
      if (cur->cas->next == root)
	return (0);
      if (add_all_link_to_lists(root, open_l, closed_l, cur->cas))
	return (1);
    }
  return (2);
}
