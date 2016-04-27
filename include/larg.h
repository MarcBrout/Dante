/*
** larg.h for larg in /home/duhieu_b/IA/dante
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Apr 27 16:56:54 2016 benjamin duhieu
** Last update Wed Apr 27 19:37:02 2016 benjamin duhieu
*/

#ifndef LARG_H_
# define LARG_H_

# define USAGE "Usage: ./largeur [file].\n"
# define PATH_ERR "Error: Labyrinth doesn't have a valid path.\n"

#include "pars.h"

/*
** free_larg.c
*/

void	free_pile(t_link *pile);
void	remove_pile(t_link *cur, t_link *root);

/*
** pile_larg.c
*/

int	add_elem_pile(t_case *cas, t_link *root, t_case *prev);
int	join_elem_to_pile(t_link *cur, t_link *pile);
void	change_graph(t_case *last);

/*
** largeur.c
*/

int	my_solv(t_case *root, t_link *pile);
int	solv_larg(t_case *root, int length);
void	print_my_graph(t_case *root, int length);

#endif /* !LARG_H_ */
