/*
** free.c for dante in /home/brout_m/RENDU/CPE/dante/profondeur
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 27 16:09:58 2016 marc brout
** Last update Wed Apr 27 16:14:48 2016 marc brout
*/

#include <stdlib.h>
#include "pars.h"

void		free_pile(t_link *root)
{
  t_link	*cur;
  t_link	*tmp;

  cur = root;
  while (cur)
    {
      tmp = cur ->next;
      free(cur);
      cur =tmp;
    }
}
