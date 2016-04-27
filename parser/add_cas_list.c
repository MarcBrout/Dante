/*
** add_cas_list.c for add_cas in /home/duhieu_b/IA/dante
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr 22 14:35:14 2016 benjamin duhieu
** Last update Wed Apr 27 22:38:58 2016 marc brout
*/

#include "pars.h"
#include "my.h"

t_case		*add_cas(t_case *cas, t_posit *pos, int length, char pas)
{
  t_case	*elem;

  if (!(elem = malloc(sizeof(t_case))))
    return (my_put_error(MALLOC_ERR), NULL);
  elem->prev = cas->prev;
  elem->next = cas;
  cas->prev->next = elem;
  cas->prev = elem;
  elem->pos.x = pos->x;
  elem->pos.y = pos->y;
  elem->pos.s_cost = 0;
  elem->pos.e_cost = 0;
  elem->pos.t_cost = 0;
  elem->pos.calc = 0;
  elem->id = pos->x + (pos->y * length);
  elem->end = 0;
  elem->pass = pas;
  elem->path = 0;
  elem->link = NULL;
  return (cas);
}

t_case		*add_cas_in_list(char *str, t_case *cas,
				 int *line, int *length)
{
  int		i;
  t_posit	pos;

  i = -1, pos.y = *line;
  while (str && str[++i])
    {
      if (str[i] != '*' && str[i] != 'X')
	return (my_put_error(CORR_ERR), NULL);
      pos.x = i;
      if (str[i] == '*')
	{
	  if (!(cas = add_cas(cas, &pos, *length, 0)))
	    return (NULL);
	}
      else if (str[i] == 'X')
	{
	  if (!(cas = add_cas(cas, &pos, *length, 1)))
	    return (NULL);
	}
      else
	break;
    }
  if ((i - 1) != *length)
    return (my_put_error(CORR_ERR), NULL);
  return (cas);
}

t_case	*length_lab(int *length, int *i,
		    t_case *cas, char *str)
{
  if (*i == 0)
    {
      *length = my_strlen(str) - 1;
      if (!(cas = add_cas_in_list(str, cas, i, length)))
	return (NULL);
      *i += 1;
    }
  else
    {
      if ((my_strlen(str) - 1) != *length)
	return (my_put_error(LENGTH_ERR), NULL);
      if (!(cas = add_cas_in_list(str, cas, i, length)))
	return (NULL);
      *i += 1;
    }
  return (cas);
}
