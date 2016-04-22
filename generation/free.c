/*
** free.c for dante in ~/RENDU/CPE/dante/generation
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Apr 18 20:36:45 2016 marc brout
** Last update Mon Apr 18 20:43:36 2016 marc brout
*/

#include <stdlib.h>
#include "generate.h"

void		free_data(t_data *data)
{
  int		i;

  free(data->check);
  free(data->corner);
  i = 0;
  while (data->maze[i])
    {
      free(data->maze[i]);
      ++i;
    }
  free(data->maze);
}
