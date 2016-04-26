/*
** move_in_list.c for move in /home/duhieu_b/IA/dante/parser
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Apr 23 15:01:21 2016 benjamin duhieu
** Last update Sat Apr 23 15:25:48 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "pars.h"

t_case	*move_down(t_case *elem, t_case *cas, int length)
{
  int		i;
  t_case	*tmp;
  t_case	*down;

  down = elem;
  tmp = elem;
  i = -1;
  while (++i <= length)
    {
      down = tmp->next;
      tmp = tmp->next;
      if (down == cas)
	return (NULL);
    }
  return (down);
}

t_case	*move_up(t_case *elem, t_case *cas, int length)
{
  int		i;
  t_case	*tmp;
  t_case	*up;

  up = elem;
  tmp = elem;
  i = -1;
  while (++i <= length)
    {
      up = tmp->prev;
      tmp = tmp->prev;
      if (up == cas)
	return (NULL);
    }
  return (up);
}
