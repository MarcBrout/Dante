/*
** link_direction.c for link in /home/duhieu_b/IA/dante
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr 22 14:33:25 2016 benjamin duhieu
** Last update Fri Apr 22 14:36:08 2016 benjamin duhieu
*/

#include "pars.h"
#include "my.h"

int	left_link(t_case *elem, t_case *cas)
{
  t_case	*left;
  t_link	*link;

  left = elem->prev;
  if (left == cas)
    return (0);
  if (!left->pass)
    {
      if (!(link = malloc(sizeof(t_link))))
	return (my_put_error(MALLOC_ERR), 1);
      link->next = NULL;
      link->cas = left;
      elem->link = link;
    }
  return (0);
}

int		right_link(t_case *elem, t_case *cas)
{
  t_case	*right;
  t_link	*link;

  right = elem->next;
  if (right == cas)
    return (0);
  if (!right->pass)
    {
      if (!(link = malloc(sizeof(t_link))))
	return (my_put_error(MALLOC_ERR), 1);
      link->next = NULL;
      link->cas = right;
      elem->link = link;
    }
  return (0);
}

int		up_link(t_case *elem, t_case *cas, int length)
{
  int		i;
  t_case	*up;
  t_link	*link;

  up = elem;
  i = -1;
  while (++i < length)
    {
      up = elem->prev;
      if (up == cas)
	return (0);
    }
  if (!up->pass)
    {
      if (!(link = malloc(sizeof(t_link))))
	return (my_put_error(MALLOC_ERR), 1);
      link->next = NULL;
      link->cas = up;
      elem->link = link;
    }
  return (0);
}

int		down_link(t_case *elem, t_case *cas, int length)
{
  int		i;
  t_case	*down;
  t_link	*link;

  down = elem;
  i = -1;
  while (++i < length)
    {
      down = elem->next;
      if (down == cas)
	return (0);
    }
  if (!down->pass)
    {
      if (!(link = malloc(sizeof(t_link))))
	return (my_put_error(MALLOC_ERR), 1);
      link->next = NULL;
      link->cas = down;
      elem->link = link;
    }
  return (0);
}
