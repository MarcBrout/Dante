/*
** calc_dist.c for calc_dist in /home/duhieu_b/IA/dante
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Apr 27 22:13:03 2016 benjamin duhieu
** Last update Wed Apr 27 23:45:14 2016 marc brout
*/

#include "astar.h"
#include "pars.h"

int		calc_dist(t_case *last, t_case *org, t_case *current)
{
  unsigned int	a;
  unsigned int	b;

  a = ((org->pos.x - current->pos.x) * (org->pos.x - current->pos.x)) +
    ((org->pos.y - current->pos.y) * (org->pos.y - current->pos.y));
  b = ((current->pos.x - last->pos.x) * (current->pos.x -last->pos.x)) +
    ((current->pos.y - last->pos.y) * (current->pos.y - last->pos.y));
  if (current->pos.calc && (a + b) < current->pos.t_cost)
    {
      current->pos.s_cost = a;
      current->pos.e_cost = b;
      current->pos.t_cost = a + b;
      current->back = org;
      return (1);
    }
  else if (!current->pos.calc)
    {
      current->pos.s_cost = a;
      current->pos.e_cost = b;
      current->pos.t_cost = a + b;
      current->back = org;
      return (0);
    }
  return (2);
}
