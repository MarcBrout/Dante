/*
** link_direction.c for link in /home/duhieu_b/IA/dante
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr 22 14:33:25 2016 benjamin duhieu
** Last update Wed Apr 27 14:53:21 2016 benjamin duhieu
*/

#include "pars.h"
#include "my.h"

int	left_link(t_case *elem, t_case *cas)
{
  t_case	*left;
  t_link	*new_elem;
  t_link	*link;

  left = elem->prev;
  if (elem->pos.x == 0 || left == cas)
    return (0);
  if (!left->pass)
    {
      if (!(link = malloc(sizeof(t_link))))
	return (my_put_error(MALLOC_ERR), 1);
      link->next = NULL;
      link->cas = left;
      if (elem->link)
	{
	  new_elem = elem->link;
	  while (new_elem->next)
	    new_elem = new_elem->next;
	  new_elem->next = link;
	}
      else
	elem->link = link;
    }
  return (0);
}

int		right_link(t_case *elem, t_case *cas, int length)
{
  t_case	*right;
  t_link	*new_elem;
  t_link	*link;

  right = elem->next;
  if (elem->pos.x == length || right == cas)
    return (0);
  if (!right->pass)
    {
      if (!(link = malloc(sizeof(t_link))))
	return (my_put_error(MALLOC_ERR), 1);
      link->next = NULL;
      link->cas = right;
      if (elem->link)
	{
	  new_elem = elem->link;
	  while (new_elem->next)
	    new_elem = new_elem->next;
	  new_elem->next = link;
	}
      else
	elem->link = link;
    }
  return (0);
}

int		up_link(t_case *elem, t_case *cas, int length)
{
  t_link	*new_elem;
  t_case	*up;
  t_link	*link;

  if (!(up = move_up(elem, cas, length)))
    return (0);
  if (!up->pass)
    {
      if (!(link = malloc(sizeof(t_link))))
	return (my_put_error(MALLOC_ERR), 1);
      link->next = NULL;
      link->cas = up;
      if (elem->link)
	{
	  new_elem = elem->link;
	  while (new_elem->next)
	    new_elem = new_elem->next;
	  new_elem->next = link;
	}
      else
	elem->link = link;
    }
  return (0);
}

int		down_link(t_case *elem, t_case *cas, int length)
{
  t_link	*new_elem;
  t_case	*down;
  t_link	*link;

  if (!(down = move_down(elem, cas, length)))
    return (0);
  if (!down->pass)
    {
      if (!(link = malloc(sizeof(t_link))))
	return (my_put_error(MALLOC_ERR), 1);
      link->next = NULL;
      link->cas = down;
      if (elem->link)
	{
	  new_elem = elem->link;
	  while (new_elem->next)
	    new_elem = new_elem->next;
	  new_elem->next = link;
	}
      else
	elem->link = link;
    }
  return (0);
}
