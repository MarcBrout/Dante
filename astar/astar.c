/*
** astar.c for astar in /home/brout_m/RENDU/CPE/dante
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 27 18:39:45 2016 marc brout
** Last update Wed Apr 27 19:24:14 2016 marc brout
*/

#include <unistd.h>
#include "astar.h"

t_link		*init_list_root()
{
  t_link	*root;

  if (!(root = malloc(sizeof(t_link))))
    return (my_put_error(MALLOC_ERR), NULL);
  root->next = root;
  root->prev = root;
  return (root);
}



int		is_in_list(t_link *root_list, t_link *link)
{
  t_link	*cur;

  cur = root_list;
  while ((cur = root_list->next) != root_list)
    {
      if (cur->cas = link->cas)
	return (1);
    }
  return (0);
}


int		launch_solve_by_astar(t_case *root)
{
  t_link	*open_l;
  t_link	*closed_l;

  if (!(open_l = init_list_root() || !(closed_l = init_list_root())))
    return (1);
  return (1);
}
