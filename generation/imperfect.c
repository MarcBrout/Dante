/*
** imperfect.c for dante in ~/RENDU/CPE/dante/generation
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Apr 18 19:56:42 2016 marc brout
** Last update Mon Apr 18 20:00:45 2016 marc brout
*/

#include <stdlib.h>
#include "my.h"
#include "generate.h"

int		can_i_put_a_star(t_data *data, char **maze,
				 int x, int y)
{
  int		i;

  i = 0;
  while (i < 4)
    {
      if (data->corner[i](data, maze, x, y) > 2)
	return (0);
      ++i;
    }
  return (1);
}

  void		go_to_imperfect_maze(t_data *data, char **maze)
{
  int		x;
  int		y;

  y = 0;
  while (maze[y])
    {
      x = 0;
      while (maze[y][x])
	{
	  if (maze[y][x] == 'X' && !(rand() % 3) &&
	      can_i_put_a_star(data, maze, x, y))
	    maze[y][x] = '*';
	  ++x;
	}
      ++y;
    }
}

int		get_loop(char **av)
{
  if (av[3])
    if (!my_strcmp(av[3], "loop"))
      return (1);
  return (0);
}
