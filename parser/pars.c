/*
** pars.c for pars in /home/duhieu_b/IA/dante/parser
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 16:37:45 2016 benjamin duhieu
** Last update Fri Apr 22 15:17:38 2016 benjamin duhieu
*/

#include "pars.h"
#include "my.h"

int		chk_start_end(t_case *cas)
{
  t_case	*elem;

  elem = cas;
  if (elem->prev->pass || elem->next->pass)
    return (my_put_error(LAB_ERR), 1);
  return (0);
}

int		my_graph(t_case *cas, int length)
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
	  if (up_link(elem, cas, length))
	    return (1);
	  if (down_link(elem, cas, length))
	    return (1);
	}
    }
  return (0);
}

int	pars(char *str, t_case *cas, t_pars *pars)
{
  char	*str;
  int	length;
  int	i;
  int	fd;

  if ((fd = open(str, O_RDONLY)) < 2)
    return (1);
  i = 0;
  length = 0;
  while ((str = get_next_line(fd)))
    if (length_lab(&length, &i, cas, str))
      return (1);
  pars->width = length;
  pars->height = i;
  cas->prev->end = 1;
  if (chk_start_end(cas))
    return (1);
  if (my_graph(cas, length))
    return (1);
  return (0);
}

int		main(int ac, char av**)
{
  t_pars	pars;

  if (ac != 2 || !av)
    return (1);
  if (!(pars.cas = malloc(sizeof(t_case))))
    return (1);
  pars.cas->next = cas;
  pars.cas->prev = cas;
  pars(av[1], pars.cas, &pars);
  return (0);
}
