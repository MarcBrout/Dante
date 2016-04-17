/*
** generate.c for dante in /home/brout_m/RENDU/CPE/dante/mazes
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Apr  7 15:16:35 2016 marc brout
** Last update Sun Apr 17 11:04:41 2016 marc brout
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "generate.h"
#include "my.h"
#include <stdio.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

void	show_maze(char **maze)
{
  int	y;

  y = 0;
  while (maze[y])
    {
      write(1, maze[y], my_strlen(maze[y]));
      if (maze[y + 1])
	write(1, "\n", 1);
      ++y;
    }
}

char	**generation(int width, int height)
{
  char	**tab;
  int	i;

  if (!(tab = malloc(sizeof(char *) * (height + 1))))
    return (NULL);
  i = 0;
  while (i < height)
    {
      if (!(tab[i] = malloc(width + 1)))
	return (NULL);
      my_bzero(tab[i], width, 'X');
      tab[i][width] = 0;
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}

int		create_file(char **av)
{
  int		fd;

  if (av[3])
    {
      if ((fd = open(av[3], O_WRONLY | O_CREAT | O_TRUNC,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
	return (perror("cf"), -1);
      return (fd);
    }
  if ((fd = open("./maze.txt", O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    return (perror("cf"), -1);
  return (fd);
}

void		init_tab_char(t_cell *cur)
{
  cur->path[S] = 1;
  cur->path[N] = 1;
  cur->path[E] = 1;
  cur->path[W] = 1;
}

void		pop_one_cell(t_cell *root)
{
  t_cell	*tmp;

  tmp = root->prev;
  root->prev = root->prev->prev;
  root->prev->next = root;
  free(tmp);
}

int		stack_one_cell(t_data *data,
			       int x, int y, int opdir)
{
  t_cell	*elem;

  if (!(elem = malloc(sizeof(t_cell))))
    return (my_put_error(M_ERROR), 1);
  elem->x = x;
  elem->y = y;
  init_tab_char(elem);
  elem->path[opdir] = 0;
  if (!data->end && x > data->width - 3)
    elem->path[N] = 0;
  if (!data->end && y > data->height - 3)
    elem->path[W] = 0;
  elem->next = data->root;
  elem->prev = data->root->prev;
  data->root->prev->next = elem;
  data->root->prev = elem;
  return (0);
}

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
      (x + 1 >= data->width || data->maze[y][x + 1] == 'X'))
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
      (x + 1 >= data->width || data->maze[y][x + 1] == 'X'))
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
      (x - 1 < 0 || data->maze[y][x - 1] == 'X'))
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
      (x + 1 > data->width || data->maze[y][x + 1] == 'X'))
    {
      data->maze[y][x] = '*';
      return (cur->path[E] = 0, 1);
    }
  return (0);
}

int		add_cell(t_data *data, t_cell *cur, int direction)
{
  if (direction == N)
    return (stack_one_cell(data, cur->x, cur->y - 1, S));
  if (direction == S)
    return (stack_one_cell(data, cur->x, cur->y + 1, N));
  if (direction == W)
    return (stack_one_cell(data, cur->x - 1, cur->y, E));
  if (direction == E)
    return (stack_one_cell(data, cur->x + 1, cur->y, W));
  return (1);
}

int		count_path(t_cell *cur, int *dir)
{
  int		i;
  int		total;

  i = 0;
  total = 0;
  while (i < 4)
    {
      if (cur->path[i])
	{
	  ++total;
	  *dir = i;
	}
      ++i;
    }
  return (total);
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
      my_printf("ret = %d\n", ret);
      dir = rand() % 4;
    }
  return (dir);
}

int		init_root(t_data *data)
{
  if (!(data->root = malloc(sizeof(t_cell))) ||
      !(data->check = malloc(sizeof(void *) * 5)))
    return (my_put_error(M_ERROR), 1);
  data->root->x = 0;
  data->root->y = 0;
  init_tab_char(data->root);
  data->root->path[N] = 0;
  data->root->path[W] = 0;
  data->root->next = data->root;
  data->root->prev = data->root;
  data->check[N] = &north;
  data->check[S] = &south;
  data->check[E] = &east;
  data->check[W] = &west;
  return (0);
}

int		change_cells(t_data *data)
{
  int		dir;
  t_cell	*cur;

  data->maze[0][0] = '*';
  data->end = 0;
  if (init_root(data))
    return (1);
  my_printf("ça boucle\n");
  while (data->root)
    {
      cur = data->root->prev;
      if ((dir = choose_random_cell(data, cur)) < 0)
	my_printf("ça pop\n"), pop_one_cell(data->root);
      else
	{
	  my_printf("dir = %d\n", dir);
	  if (add_cell(data, cur, dir))
	    return (1);
	}
      if (data->root->prev->x == data->width - 1 &&
	  data->root->prev->y == data->height - 1)
	data->end = 1;
    }
  return (0);
}

int		generate_lab(char **av)
{
  t_data	data;

  if (!(data.width = my_getnbr(av[1])))
    return (my_put_error(W_ERROR), 1);
  if (!(data.height = my_getnbr(av[2])))
    return (my_put_error(H_ERROR), 1);
  if (!(data.maze = generation(data.width, data.height)))
    return (my_put_error(G_ERROR), 1);
  if ((data.fd = create_file(av)) < 0)
    return (my_put_error(F_ERROR), 1);
  if (change_cells(&data))
    return (1);
  show_maze(data.maze);
  close(data.fd);
  return (0);
}

int	main(int ac, char **av)
{

  if (ac < 2)
    return (my_put_usage(av), 1);
  if (generate_lab(av))
    return (1);
  return (0);
}
