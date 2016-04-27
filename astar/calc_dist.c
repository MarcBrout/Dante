/*
** calc_dist.c for calc_dist in /home/duhieu_b/IA/dante
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Apr 27 22:13:03 2016 benjamin duhieu
** Last update Wed Apr 27 22:28:01 2016 benjamin duhieu
*/

#include "astar.h"
#include "pars.h"

void	calc_dist(t_case *last, t_case *origin, t_case *current)
{
  current->s_cost = ((origin->pos.x - current->pos.x) *
		     (origin->pos.x - current->pos.x)) +
    ((origin->pos.y - current->pos.y) * (origin->pos.y - current->pos.y));
  current->e_cost = ((current->pos.x - last->pos.x) *
		     (current->pos.x -last->pos.x)) +
    ((current->pos.y - last->pos.y) * (current->pos.y - last->pos.y));
  current->t_cost = current->s_cost + current->e_cost;
}
