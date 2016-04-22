/*
** add_cas_list.c for add_cas in /home/duhieu_b/IA/dante
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr 22 14:35:14 2016 benjamin duhieu
** Last update Fri Apr 22 14:35:45 2016 benjamin duhieu
*/

#include "pars.h"
#include "my.h"

int		add_cas(t_case *cas, t_posit *pos, int *length, char pas)
{
  t_case	*elem;

  if (!(elem = malloc(sizeof(t_case))))
    return (my_put_error(MALLOC_ERR), 1);
  elem->next = cas->prev;
  elem->prev = cas;
  cas->prev->next = elem;
  cas->prev = elem;
  elem->x = pos->x;
  elem->y = pos->y;
  elem->id = pos->x + (pos->y * *length);
  elem->end = 0;
  elem->pass = pas;
  elem->path = 0;
}

int		add_cas_in_list(char *str, t_case *cas, int *line, int *length)
{
  int		i;
  t_posit	pos;

  i = -1;
  pos.y = *line;
  while (str && str[++i])
    {
      if (str[i] != '*' && str[i] != 'X' && str[i] != '\n')
	return (my_put_error(CORR_ERR), 1);
      pos.x = i;
      if (str[i] == '*')
	add_cas(cas, &pos, *length, 0);
      else if (str[i] = 'X')
	add_cas(cas, &pos, *length, 1);
      else
	break;
    }
  if (i != length)
    return (my_put_error(COR_ERR), 1);
  return (0);
}

int	lenght_lab(int *lenght, int *i, t_case *cas, char *str)
{
  if (*i == 0)
    {
      *length = my_strlen(str) - 1;
      if (!(cas = add_cas_in_list(str, cas, *i, *length)))
	return (1);
      *i++;
    }
  else
    {
      if (my_strlen(str) != length)
	return (my_put_error(LENGTH_ERR), 1);
      if (!(cas = add_cas_in_list(str, cas, *i, length)))
	return (1);
      *i++;
    }
  return (0);
}
