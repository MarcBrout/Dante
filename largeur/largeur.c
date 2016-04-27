/*
** largeur.c for largeur in /home/duhieu_b/IA/dante/largeur
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Apr 27 15:22:31 2016 benjamin duhieu
** Last update Wed Apr 27 19:54:44 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "pars.h"
#include "larg.h"
#include "my.h"

int		my_solv(t_case *root, t_link *pile)
{
  int		chk;

  if (add_elem_pile(root->next, pile, NULL))
    return (my_put_error(MALLOC_ERR), 1);
  root->next->path = 1;
  if (root->next->end)
    return (0);
  while (pile->next != pile)
    {
      if ((chk = join_elem_to_pile(pile->next, pile)) == 1)
	return (my_put_error(MALLOC_ERR), 1);
      else if (chk == 2)
	{
	  free_pile(pile);
	  return (change_graph(root->prev), 0);
	}
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
      else if (elem->path <= 0)
	my_printf("*");
      else
	my_printf("o");
      i++;
      if (i >= length + 1)
	{
	  my_printf("\n");
	  i = 0;
	}
      elem = elem->next;
    }
}

int		solv_larg(t_case *root, int length)
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
  if (solv_larg(parser->cas, parser->width))
    {
      free(parser);
      return (1);
    }
  free_graph(parser);
  return (0);
}
