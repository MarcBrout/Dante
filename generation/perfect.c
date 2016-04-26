/*
** perfect.c for dante in ~/RENDU/CPE/dante/generation
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Apr 18 20:02:31 2016 marc brout
** Last update Fri Apr 22 16:11:22 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "generate.h"
#include "my.h"

void		pop_one_cell(t_cell *root, char *go)
{
  t_cell	*tmp;

  tmp = root->prev;
  root->prev = root->prev->prev;
  if (tmp->x == root->prev->x + 1)
    root->prev->path[E] = 0;
  else if (tmp->x == root->prev->x - 1)
    root->prev->path[W] = 0;
  else if (tmp->y == root->prev->y + 1)
    root->prev->path[S] = 0;
  else
    root->prev->path[N] = 0;
  root->prev->next = root;
  if (tmp == root)
    *go = 0;
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

void		change_dir_end_cell(t_data *data, int dir)
{
  if (dir == E)
    data->root->prev->path[N] = 1;
  else if (dir == N)
    data->root->prev->path[E] = 1;
}

int		go_to_perfect_maze(t_data *data)
{
  char		go;
  int		dir;
  t_cell	*cur;

  data->maze[0][0] = '*';
  data->end = 0;
  if (init_root(data))
    return (my_put_error(GEN_ERROR), 1);
  go = 1;
  while (go)
    {
      cur = data->root->prev;
      if ((dir = choose_random_cell(data, cur)) < 0)
	pop_one_cell(data->root, &go);
      else
	{
	  if (add_cell(data, cur, dir))
	    return (my_put_error(GEN_ERROR), 1);
	  if (data->root->prev->x == data->width - 1 &&
	      data->root->prev->y == data->height - 1)
	    data->end = 1, change_dir_end_cell(data, dir);
	}
    }
  return (0);
}
