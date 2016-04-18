/*
** go.c for dante in /home/brout_m/RENDU/CPE/dante/mazes
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Apr 15 11:36:07 2016 marc brout
** Last update Mon Apr 18 20:21:30 2016 marc brout
*/

#include <stdlib.h>
#include "my.h"
#include "generate.h"

int		north(t_data *data, t_cell *cur)
{
  int		y;
  int		x;

  y = cur->y - 1;
  x = cur->x;
  if (y < 0)
    return (cur->path[N] = 0, 0);
  if ((y - 1 < 0 || data->maze[y - 1][x] == 'X') &&
      (x - 1 < 0 || data->maze[y][x - 1] == 'X') &&
      (x + 1 >= data->width || data->maze[y][x + 1] == 'X') &&
      (x - 1 < 0 || y - 1 < 0 || data->maze[y - 1][x - 1] == 'X') &&
      (x + 1 >= data->width || y - 1 < 0 ||
       data->maze[y - 1][x + 1] == 'X'))
    {
      data->maze[y][x] = '*';
      return (1);
    }
  return (cur->path[N] = 0, 0);
}

int		south(t_data *data, t_cell *cur)
{
  int		y;
  int		x;

  y = cur->y + 1;
  x = cur->x;
  if (y >= data->height)
    return (cur->path[S] = 0, 0);
  if ((y + 1 >= data->height || data->maze[y + 1][x] == 'X') &&
      (x - 1 < 0 || data->maze[y][x - 1] == 'X') &&
      (x + 1 >= data->width || data->maze[y][x + 1] == 'X') &&
      (x - 1 < 0 || y + 1 >= data->height ||
       data->maze[y + 1][x - 1] == 'X') &&
      (x + 1 >= data->width || y + 1 >= data->height ||
       data->maze[y + 1][x + 1] == 'X'))

    {
      data->maze[y][x] = '*';
      return (1);
    }
  return (cur->path[S] = 0, 0);
}

int		west(t_data *data, t_cell *cur)
{
  int		y;
  int		x;

  y = cur->y;
  x = cur->x - 1;
  if (x < 0)
    return (cur->path[W] = 0, 0);
  if ((y - 1 < 0 || data->maze[y - 1][x] == 'X') &&
      (y + 1 >= data->height || data->maze[y + 1][x] == 'X') &&
      (x - 1 < 0 || data->maze[y][x - 1] == 'X') &&
      (x - 1 < 0 || y + 1 >= data->height ||
       data->maze[y + 1][x - 1] == 'X') &&
      (x - 1 < 0 || y - 1 < 0 || data->maze[y - 1][x - 1] == 'X'))
    {
      data->maze[y][x] = '*';
      return (1);
    }
  return (cur->path[W] = 0, 0);
}

int		east(t_data *data, t_cell *cur)
{
  int		y;
  int		x;

  y = cur->y;
  x = cur->x + 1;
  if (x >= data->width)
    return (cur->path[E] = 0, 0);
  if ((y - 1 < 0 || data->maze[y - 1][x] == 'X') &&
      (y + 1 >= data->height || data->maze[y + 1][x] == 'X') &&
      (x + 1 >= data->width || data->maze[y][x + 1] == 'X') &&
      (x + 1 >= data->width || y + 1 >= data->height ||
       data->maze[y + 1][x + 1] == 'X') &&
      (x + 1 >= data->width || y - 1 < 0 ||
       data->maze[y - 1][x + 1] == 'X'))

    {
      data->maze[y][x] = '*';
      return (cur->path[E] = 0, 1);
    }
  return (cur->path[E] = 0, 0);
}

int		choose_random_cell(t_data *data, t_cell *cur)
{
  int		ret;
  int		dir;

  ret = count_path(cur, &dir);
  if (ret == 1 && data->check[dir](data, cur))
    return (dir);
  else if (!ret)
    return (-1);
  dir = rand() % 4;
  while (!cur->path[dir] || !data->check[dir](data, cur))
    {
      if (!(ret = count_path(cur, &dir)))
	return (-1);
      if (ret == 1)
	continue;
      dir = rand() % 4;
    }
  return (dir);
}
