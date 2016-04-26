/*
** generate.c for dante in /home/brout_m/RENDU/CPE/dante/mazes
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Apr  7 15:16:35 2016 marc brout
** Last update Tue Apr 26 11:53:50 2016 marc brout
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "generate.h"
#include "my.h"

int		create_file(char **av)
{
  int		fd;

  if (av[3] && my_strcmp(av[3], "loop"))
    {
      if ((fd = open(av[3], O_WRONLY | O_CREAT | O_TRUNC,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
	return (my_put_error(F_ERROR), -1);
      return (fd);
    }
  else if (av[3] && av[4])
    {
      if ((fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
	return (my_put_error(F_ERROR), -1);
      return (fd);
    }
  if ((fd = open("./maze", O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    return (my_put_error(F_ERROR), -1);
  return (fd);
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

int		write_maze_to_file(int fd, char **maze)
{
  int		y;

  y = 0;
  while (maze[y])
    {
      if (write(fd, maze[y], my_strlen(maze[y])) < 0)
	return (my_put_error(WRITE_ERROR), 1);
      ++y;
      if (maze[y])
	write(fd, "\n", 1);
    }
  return (0);
}

int		generate_lab(char **av)
{
  t_data	data;
  int		loop;
  int		fd;

  if (!(data.width = my_getnbr(av[1])))
    return (my_put_error(W_ERROR), 1);
  if (!(data.height = my_getnbr(av[2])))
    return (my_put_error(H_ERROR), 1);
  loop = get_loop(av);
  if (!(data.maze = generation(data.width, data.height)) ||
      go_to_perfect_maze(&data))
    return (1);
  if (loop)
    go_to_imperfect_maze(&data, data.maze);
  if ((fd = create_file(av)) < 0 ||
      write_maze_to_file(fd, data.maze))
    return (1);
  free_data(&data);
  close(fd);
  return (0);
}

int	main(int ac, char **av)
{
  srand(time(0));
  if (ac < 2)
    return (my_put_usage(av), 1);
  if (generate_lab(av))
    return (1);
  return (0);
}
