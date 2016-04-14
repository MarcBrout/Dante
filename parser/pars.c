/*
** pars.c for pars in /home/duhieu_b/IA/dante/parser
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 16:37:45 2016 benjamin duhieu
** Last update Thu Apr 14 12:40:28 2016 benjamin duhieu
*/

#include "lemin.h"

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  while (str && str[++i]);
  return (i);
}

void		my_put_error(char *str)
{
  write(2, str, my_strlen(str));
}

int		add_cas(t_case *cas, int num, char pas)
{
  t_case	*elem;

  if (!(elem = malloc(sizeof(t_case))))
    return (my_put_error(MALLOC_ERR), 1);
  elem->next = cas->prev;
  elem->prev = cas;
  cas->prev->next = elem;
  cas->prev = elem;
  elem->id = num;
  elem->pass = pas;
}

int		add_cas_in_list(char *str, t_case *cas, int *line, int *lenght)
{
  int		i;

  i = -1;
  while (str && str[++i])
    {
      if (str[i] != '*' && str[i] != 'X' && str[i] != '\n')
	return (my_put_error(CORR_ERR), 1);
      if (str[i] == '*')
	add_cas(cas, (*line * *lenght) + i, 0);
      else if (str[i] = 'X')
	add_cas(cas, (*line * *lenght) + i, 1);
      else
	break;
    }
  if (i != lenght)
    return (my_put_error(COR_ERR), 1);
  return (0);
}

int	lenght_lab(int *lenght, int *i, t_case *cas, char *str))
{
  if (*i == 0)
    {
      *lenght = my_strlen(str) - 1;
      if (!(cas = add_cas_in_list(str, cas, *i, *lenght)))
	return (1);
      *i++;
    }
  else
    {
      if (my_strlen(str) != lenght)
	return (my_put_error(LENGHT_ERR), 1);
      if (!(cas = add_cas_in_list(str, cas, *i, lenght)))
	return (1);
    }
  return (0);
}

int		chk_start_end(t_case *cas)
{
  t_case	*elem;

  elem = cas;
  if (elem->prev->pass || elem->next->pass)
    return (my_put_error(LAB_ERR), 1);
  return (0);
}

int		left_link(t_case *elem, t_case *cas)
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

int		up_link(t_case *elem, t_case *cas, int lenght)
{
  int		i;
  t_case	*up;
  t_link	*link;

  up = elem;
  i = -1;
  while (++i < lenght)
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

int		down_link(t_case *elem, t_case *cas, int lenght)
{
  int		i;
  t_case	*down;
  t_link	*link;

  down = elem;
  i = -1;
  while (++i < lenght)
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

int		my_graph(t_case *cas, int lenght)
{
  t_case	*elem;

  elem = cas->next;
  while (elem != cas)
    {
      if (!elem->pass)
	{
	  if (left_link(elem, cas))
	    return (1);
	  if (right_link(elem, cas))
	    return (1);
	  if (up_link(elem, cas, lenght))
	    return (1);
	  if (down_link(elem, cas, lenght))
	    return (1);
	}
    }
  return (0);
}

int	pars(char *str, t_case *cas)
{
  char	*str;
  int	lenght;
  int	i;
  int	fd;

  if ((fd = open(str, O_RDONLY)) < 2)
    return (1);
  i = 0;
  lenght = 0;
  while ((str = get_next_line(fd)))
    if (lenght_lab(&lenght, &i, cas, str))
      return (1);
  if (chk_start_end(cas))
    return (1);
  if (my_graph(cas, lenght))
    return (1);
  return (0);
}

int		main(int ac, char av**)
{
  t_case	*cas;

  if (ac != 2 || !av)
    return (1);
  if (!(cas = malloc(sizeof(t_case))))
    return (1);
  cas->next = cas;
  cas->prev = cas;
  pars(av[1], cas);
  return (0);
}
