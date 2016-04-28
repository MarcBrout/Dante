/*
** astar.h for dante in /home/brout_m/RENDU/CPE/dante
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 27 18:40:02 2016 marc brout
** Last update Wed Apr 27 23:47:22 2016 marc brout
*/

#ifndef ASTAR_H_
# define ASTAR_H_

# define NO_PATH "No path found.\n"
# define USAGE "./solver [MAP].\n"

# include "pars.h"


int			calc_dist(t_case *last,
				  t_case *origin,
				  t_case *current);
int			launch_solve_by_astar(t_case *root);
#endif /* !ASTAR_H_ */
