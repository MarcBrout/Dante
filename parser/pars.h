/*
** pars.h for pars in /home/duhieu_b/IA/dante/parser
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Apr  7 15:34:59 2016 benjamin duhieu
** Last update Wed Apr 20 14:54:00 2016 benjamin duhieu
*/

#ifndef PARS_H_
# define PARS_H_

# define MALLOC_ERR "Can't perform malloc.\n"
# define LENGHT_ERR "Error: The labyrinth isn't a rectangle.\n"
# define LAB_ERR "Error: Labyrinth haven't a start or an end.\n"
# define CORR_ERR "Error: Labyrinth is corrupt.\n"

typedef struct s_posit
{
  int		x;
  int		y;
}		t_posit;

typedef	struct s_case
{
  int		id;
  char		end;
  char		pass;
  t_posit	pos;
  struct s_case	*next;
  struct s_case	*prev;
  struct s_link	*link;
}		t_case;

typedef	struct	s_link
{
  t_case	*cas;
  struct s_link	*next;
}		t_link;

typedef	struct s_pars
{
  int		width;
  int		height;
  t_case	*cas;
  /* t_graph	*graph; */
}		t_pars;

#endif /* !PARS_H_ */
