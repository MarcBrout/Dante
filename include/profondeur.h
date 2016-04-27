/*
** profondeur.h for dante in ~/RENDU/CPE/dante/include
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Apr 22 11:31:19 2016 marc brout
** Last update Wed Apr 27 16:14:12 2016 marc brout
*/

#ifndef PROFONDEUR_H_
# define PROFONDEUR_H_

# define NO_PATH "No path found.\n"
# define USAGE "./solver [FILE]\n"

#include "pars.h"

/*
** resolution.c
*/

int		add_this_link(t_link **last, t_link *link);
int		add_to_pile(char *go_back, t_link **last);
void		remove_from_pile(t_link **last);
t_link		*init_pile_root(t_case *first);
int		launch_solve_by_length(t_case *root);

/*
** solver.c
*/

char		check_loop(t_case *cas);
int		write_graph(t_case *root, int width);
int		solve_by_length(t_case *root, int width);

/*
** free.c
*/

void		free_pile(t_link *root);

#endif /* !PROFONDEUR_H_ */
