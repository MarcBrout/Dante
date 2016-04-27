/*
** free_graph.c for dante in /home/brout_m/RENDU/CPE/dante/parser
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 27 16:15:49 2016 marc brout
** Last update Wed Apr 27 16:49:10 2016 marc brout
*/

#include <stdlib.h>
#include "pars.h"

void		free_link(t_link *first)
{
  t_link	*cur;
  t_link	*tmp;

  cur = first;
  while (cur)
    {
      tmp = cur->next;
      free(cur);
      cur = tmp;
    }
}

void		free_graph(t_pars *parser)
{
  t_case	*cur;
  t_case	*tmp;

  cur = parser->cas->next;
  while (cur != parser->cas)
    {
      tmp = cur->next;
      free_link(cur->link);
      free(cur);
      cur = tmp;
    }
  free(parser->cas);
  free(parser);
}
