/*
** solver.c for dante in /home/brout_m/RENDU/CPE/dante/profondeur
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Apr 19 11:08:26 2016 marc brout
** Last update Tue Apr 26 12:58:09 2016 marc brout
*/

#include "my.h"
#include "parser.h"
#include "longueur.h"

int		add_this_link(t_link **last, t_link *link)
{
  if (!(*last->next = malloc(sizeof(t_link))))
    return (my_put_error(MALLOC_ERR), 1);
  *last->next->cas = link->cas;
  *last->next->next = NULL;
  *last->next->prev = *last;
  *last = last->next;
  return (0);
}

int		add_to_pile(char *go_back, t_link **last)
{
  t_link	*link;
  int		total;

  total = 0;
  link = *last->cas->link;
  while (link)
    {
      if (!link->cas->path && !link->cas->pass)
	{
	  if (add_this_link(last, link))
	    return (1);
	  ++total;
	}
      link = link->next;
    }
  *go_back = (total) ? 0 : 1;
  return (0);
}

void		remove_from_pile(t_link **last)
{
  *last->cas->path = -1;
  if (*last->prev)
    {
      *last = *last->prev;
      free(*last->next);
      *last->next = NULL;
    }
  else
    {
      free(*last);
      *last = NULL;
    }
}

t_link		*init_pile_root(t_case *first)
{
  t_link	*root;

  if (!(root = malloc(sizeof(t_link))))
    return (my_put_error(MALLOC_ERR), NULL);
  root->cas = first;
  root->next = NULL;
  root->prev = NULL;
  first->path = 1;
  return (root);
}

int		launch_solve_by_lenght(t_case *root)
{
  t_link	*last;
  char		go_back;

  if (!(last = init_pile_root(root->next)))
    return (1);
  go_back = 0;
  while (last)
    {
      last->cas->path = 1;
      if (last->cas->next == root)
	return (0);
      if (add_to_pile(&go_back, &last))
	return (1);
      if (go_back)
	{
	  remove_from_pile(&last);
	  go_back = 0;
	}
    }
  return (2);
}

int		write_graph(t_case *root, int width, int fd)
{
  t_case	*cur;
  int		i;

  cur = root;
  i = -1;
  while ((cur = cur->next) && cur != root && ++i >= 0)
    {
      if (!cur->pass && cur->path)
	{
	  if (write(fd, "o", 1) < 1)
	    return (1);
	}
      else if (!cur->pass)
	{
	  if (write(fd, "*", 1) < 1)
	    return (1);
	}
      else
	if (write(fd, "X", 1) < 1)
	  return (1);
      if (i && !(i % width))
	if (write(1, "\n", 1) < 1)
	  return (1);
    }
  return (0);
}

char		*concat_str(char *filename, char *add)
{
  char		*concat;
  int		lenfil;
  int		lenadd;
  int		i;
  int		j;

  lenfil = my_strlen(filename);
  add = my_strlen(add);
  if (!(concat = malloc(lenfil + add + 1)))
    return (NULL);
  my_bzero(concat, lenfil + add + 1, 0);
  i = -1;
  j = -1;
  while (filename[++i])
    concat[++j] = filename[i];
  i = -1;
  while (add[++i])
    concat[++j] = add[i];
  return (concat);
}

int		open_file(char *filename)
{
  int		fd;

  if ((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    return (my_put_error(F_ERROR), -1);
  return (fd);
}

int		solve_by_lenght(t_case *root, int width,
				char *filename)
{
  int		ret;
  int		fd;
  char		*result;

  if (!(result = concat_str(filename, "_solved")))
    return (1);
  if ((ret = launch_solve_by_lenght(root)) == 1)
    return (1);
  else if (ret == 2)
    return (my_put_error(NO_PATH, 0));
  if ((fd = open_file(filename)) < 0)
    return (1);
  write_graph(root, width, fd);
  return (0);
}
