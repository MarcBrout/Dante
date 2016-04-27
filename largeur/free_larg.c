/*
** free_larg.c for free in /home/duhieu_b/IA/dante/largeur
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Apr 27 19:30:12 2016 benjamin duhieu
** Last update Wed Apr 27 19:41:15 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "pars.h"
#include "larg.h"

void		remove_pile(t_link *cur, t_link *root)
{
  cur->next->prev = root;
  root->next = cur->next;
  free(cur);
}

void		free_pile(t_link *pile)
{
  t_link	*elem;
  t_link	*tmp;

  elem = pile->next;
  while (elem != pile)
    {
      tmp = elem;
      elem = elem->next;
      remove_pile(tmp, pile);
    }
  free(elem);
}
