/*
** pars.h for pars in /home/duhieu_b/IA/dante/parser
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Apr  7 15:34:59 2016 benjamin duhieu
** Last update Wed Apr 27 17:46:18 2016 benjamin duhieu
*/

#ifndef PARS_H_
# define PARS_H_

# define MALLOC_ERR "Can't perform malloc.\n"
# define LENGTH_ERR "Error: The labyrinth isn't a rectangle.\n"
# define LAB_ERR "Error: Labyrinth doesn't have a start or an end.\n"
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
  char		path;
  struct s_case	*next;
  struct s_case	*prev;
  struct s_link	*link;
  struct s_case	*back;
}		t_case;

typedef	struct	s_link
{
  t_case	*cas;
  struct s_link	*next;
  struct s_link *prev;
}		t_link;

typedef	struct s_pars
{
  int		width;
  int		height;
  t_case	*cas;
}		t_pars;

/*
** pars.c
*/

int		chk_start_end(t_case *cas);
t_case		*my_graph(t_case *cas, int length);
int		pars(char *str, t_case *cas, t_pars *pars);
t_pars		*recup_graph(char *file);

/*
** link_direction.c
*/

int		down_link(t_case *elem, t_case *cas, int length);
int		left_link(t_case *elem, t_case *cas);
int		up_link(t_case *elem, t_case *cas, int length);
int		right_link(t_case *elem, t_case *cas, int length);

/*
** add_cas_in_list.c
*/

t_case		*add_cas(t_case *cas, t_posit *pos, int length, char pas);
t_case		*add_cas_in_list(char *str, t_case *cas, int *line, int *length);
t_case		*length_lab(int *length, int *i, t_case *cas, char *str);

/*
** move_in_list.c
*/

t_case		*move_down(t_case *elem, t_case *cas, int length);
t_case		*move_up(t_case *elem, t_case *cas, int length);

/*
** free_graph.c
*/

void		free_link(t_link *first);
void		free_graph(t_pars *parser);

#endif /* !PARS_H_ */
