/*
** largeur.c for largeur in /home/duhieu_b/IA/dante/largeur
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Apr 27 15:22:31 2016 benjamin duhieu
** Last update Wed Apr 27 17:03:24 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "pars.h"
#include "larg.h"
#include "my.h"

int		add_elem_pile(t_cas *cas, t_link *root, t_link *prev)
{
  t_link	*new;

  if (!(new = malloc(sizeof(t_link *))))
    return (1);
  new->back = prev;
  new->next = root;
  new->prev = root->prev;
  root->prev->next = new;
  root->prev = new;
  new->cas = cas;
  return (0);
}

void		remove_pile(t_link *cur, t_link *root)
{
  cur->next->prev = root;
  root->next = cur->next;
  free(cur);
}

void		change_graph(t_link *last)
{
  t_link	*elem;

  elem = last;
  while (elem->back)
    {
      elem->cas->path = 1;
      elem = elem->back;
    }
}

int		chk_id(int id, t_link *pile)
{
  t_link	*elem;

  elem = pile->next;
  while (elem != pile)
    {
      if (elem->cas->id == id)
	return (1);
      elem = elem-next;
    }
  return (0);
}

int		join_elem_to_pile(t_link *cur, t_link *pile)
{
  t_link	*elem;

  elem = cur->cas->link;
  while (elem)
    {
      if (chk_id(elem->cas->id, pile))
	elem = elem->next, continue;
      else
	{
	  if (add_elem_pile(elem->cas, pile, cur))
	    return (1);
	  if (elem->cas->end)
	    return (change_graph(elem), 2);
	  elem = elem->next;
	}
    }
  return (0);
}

int		my_solv(t_cas *root, t_link *pile)
{
  int		chk;

  if (add_elem_pile(root->next, pile, NULL))
    return (my_put_error(MALLOC_ERR), 1);
  while (pile->next != pile)
    {
      if ((chk = join_elem_to_pile(pile->next, pile)) == 1)
	return (my_put_error(MALLOC_ERR), 1);
      else if (chk == 2)
	return (0);
      remove_pile(pile->next, pile);
    }
  return (2);
}

void		print_my_graph(t_case *root, int length)
{
  t_case	*elem;
  int		i;

  elem = root->next;
  i = 0;
  while (elem != root)
    {
      if (elem->pass)
	my_printf("X");
      else if (!elem->path)
	my_printf("*");
      else
	my_printf("o");
      i++;
      if (i >= length)
	{
	  my_printf("\n");
	  i = 0;
	}
    }
}

int		solv_larg(t_cas	*root, int length)
{
  t_link	*pile;
  int		chk;

  if (!(pile = malloc(sizeof(t_link))))
    return (1);
  pile->next = pile;
  pile->prev = pile;
  if ((chk = my_solv(root, pile)) == 1)
    return (1);
  else if (chk == 2)
    return (my_put_error(PATH_ERR), 1);
  else
    print_my_graph(root, length);
  return (0);
}

int		main(int ac, char **av)
{
  t_pars	*parser;

  if (ac < 2)
    return (my_put_error(USAGE), 1);
  if (!(parser = recup_graph(av[1])))
    return (1);
  return (solv_larg(parser->cas, parser->width));
}
