/*
** pars.c for pars in /home/duhieu_b/IA/dante/parser
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Apr  8 16:37:45 2016 benjamin duhieu
** Last update Sat Apr 23 15:35:29 2016 benjamin duhieu
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "pars.h"
#include "get_next_line.h"
#include "my.h"

int		chk_start_end(t_case *cas)
{
  t_case	*elem;

  elem = cas;
  if (elem->prev->pass || elem->next->pass)
    return (my_put_error(LAB_ERR), 1);
  return (0);
}

t_case		*my_graph(t_case *cas, int length)
{
  t_case	*elem;

  elem = cas->next;
  while (elem != cas)
    {
      if (!elem->pass)
	{
	  if (left_link(elem, cas))
	    return (NULL);
	  if (right_link(elem, cas))
	    return (NULL);
	  if (up_link(elem, cas, length))
	    return (NULL);
	  if (down_link(elem, cas, length))
	    return (NULL);
	}
      elem = elem->next;
    }
  return (cas);
}

void		chk_graph(t_case *cas)
{
  int		i;
  t_case	*elem;
  t_link	*new_elem;

  elem = cas->next;
  while (elem != cas)
    {
      new_elem = elem->link;
      i = 0;
      while (new_elem)
	{
	  i++;
	  new_elem = new_elem->next;
	}
      elem = elem->next;
    }
}

int	pars(char *file, t_case *cas, t_pars *parse)
{
  char	*str;
  int	length;
  int	i;
  int	fd;

  if ((fd = open(file, O_RDONLY)) < 2)
    return (1);
  i = 0;
  length = 0;
  while ((str = get_next_line(fd)))
    if (!(cas = length_lab(&length, &i, cas, str)))
      return (1);
  parse->width = length;
  parse->height = i;
  cas->prev->end = 1;
  if (chk_start_end(cas))
    return (1);
  if (!(cas = my_graph(cas, length)))
    return (1);
  chk_graph(cas);
  return (0);
}

t_pars		*recup_graph(t_pars *parse, char *file)
{
  if (!(parse->cas = malloc(sizeof(t_case))))
    return (NULL);
  parse->cas->next = parse->cas;
  parse->cas->prev = parse->cas;
  pars(file, parse->cas, parse);
  return (parse);
}
