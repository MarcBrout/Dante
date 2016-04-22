/*
** init.c for dante in /home/brout_m/RENDU/CPE/dante/generation
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Apr 18 20:08:22 2016 marc brout
** Last update Mon Apr 18 20:16:43 2016 marc brout
*/

#include <stdlib.h>
#include "generate.h"

char	**generation(int width, int height)
{
  char	**tab;
  int	i;

  if (!(tab = malloc(sizeof(char *) * (height + 1))))
    return (my_put_error(G_ERROR), NULL);
  i = 0;
  while (i < height)
    {
      if (!(tab[i] = malloc(width + 1)))
	return (my_put_error(G_ERROR), NULL);
      my_bzero(tab[i], width, 'X');
      tab[i][width] = 0;
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}

void		init_tab_char(t_cell *cur)
{
  cur->path[S] = 1;
  cur->path[N] = 1;
  cur->path[E] = 1;
  cur->path[W] = 1;
}

int		init_root(t_data *data)
{
  if (!(data->root = malloc(sizeof(t_cell))) ||
      !(data->check = malloc(sizeof(void *) * 5)) ||
      !(data->corner = malloc(sizeof(void *) * 5)))
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
  data->corner[0] = &how_many_stars_in_corner_nw;
  data->corner[1] = &how_many_stars_in_corner_ne;
  data->corner[2] = &how_many_stars_in_corner_sw;
  data->corner[3] = &how_many_stars_in_corner_se;
  return (0);
}
