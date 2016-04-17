/*
** generate.h for dante in /home/brout_m/RENDU/CPE/dante/include
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Apr  7 15:23:45 2016 marc brout
** Last update Fri Apr 15 18:11:42 2016 marc brout
*/

#ifndef GENERATE_H_
# define GENERATE_H_

# define M_ERROR "Can't perform malloc\n"
# define W_ERROR "Expected positive width.\n"
# define H_ERROR "Expected positive height.\n"
# define G_ERROR "Error while generating labyrinth.\n"
# define F_ERROR "Error while creating file.\n"

typedef enum		e_direction
  {
    N			= 0,
    S			= 1,
    E			= 2,
    W			= 3
  }			t_direction;

typedef struct		s_cell
{
  int			x;
  int			y;
  char			path[4];
  struct s_cell		*next;
  struct s_cell		*prev;
}			t_cell;

typedef struct		s_data
{
  int			fd;
  int			width;
  int			height;
  int			(**check)(struct s_data *, t_cell *);
  char			**maze;
  char			end;
  t_cell		*root;
}			t_data;

int			my_strlen(char *str);
void			my_bzero(void *ptr, int size, char c);
int			my_getnbr(char *str);
void			my_put_error(const char *str);
void			my_put_usage(char **av);


#endif /* !GENERATE_H_ */
