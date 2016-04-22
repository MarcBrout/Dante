/*
** check_corners.c for dante in /home/brout_m/RENDU/CPE/dante/generation
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Apr 18 19:48:07 2016 marc brout
** Last update Mon Apr 18 19:49:18 2016 marc brout
*/

#include	"generate.h"

int		how_many_stars_in_corner_nw(UNUSED t_data *data,
					    char **maze, int x, int y)
{
  int		total;

  total = 0;
  if (x - 1 >= 0 && maze[y][x - 1] == '*')
    ++total;
  if (y - 1 >= 0 && x - 1 >= 0 && maze[y - 1][x - 1] == '*')
    ++total;
  if (y - 1 >= 0 && maze[y - 1][x] == '*')
    ++total;
  return (total);
}

int		how_many_stars_in_corner_ne(t_data *data, char **maze,
					    int x, int y)
{
  int		total;

  total = 0;
  if (x + 1 < data->width && maze[y][x + 1] == '*')
    ++total;
  if (y - 1 >= 0 && x + 1 < data->width && maze[y - 1][x + 1] == '*')
    ++total;
  if (y - 1 >= 0 && maze[y - 1][x] == '*')
    ++total;
  return (total);
}

int		how_many_stars_in_corner_se(t_data *data, char **maze,
					    int x, int y)
{
  int		total;

  total = 0;
  if (x + 1 < data->width && maze[y][x + 1] == '*')
    ++total;
  if (y + 1 < data->height &&
      x + 1 < data->width && maze[y + 1][x + 1] == '*')
    ++total;
  if (y + 1 < data->height && maze[y + 1][x] == '*')
    ++total;
  return (total);
}

int		how_many_stars_in_corner_sw(t_data *data, char **maze,
					    int x, int y)
{
  int		total;

  total = 0;
  if (x - 1 >= 0 && maze[y][x - 1] == '*')
    ++total;
  if (y + 1 < data->height &&
      x - 1 >= 0 && maze[y + 1][x - 1] == '*')
    ++total;
  if (y + 1 < data->height && maze[y + 1][x] == '*')
    ++total;
  return (total);
}
