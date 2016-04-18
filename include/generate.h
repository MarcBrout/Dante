/*
** generate.h for dante in ~/RENDU/CPE/dante/include
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Apr  7 15:23:45 2016 marc brout
** Last update Mon Apr 18 20:15:53 2016 marc brout
*/

#ifndef GENERATE_H_
# define GENERATE_H_
# define UNUSED __attribute__((__unused__))

# define M_ERROR "Can't perform malloc\n"
# define W_ERROR "Expected positive width.\n"
# define H_ERROR "Expected positive height.\n"
# define G_ERROR "Error while mallocing labyrinth.\n"
# define F_ERROR "Error while creating file.\n"
# define WRITE_ERROR "Error while writing maze\n"
# define GEN_ERROR "Error while generating labyrinthe\n"


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
  int			(**corner)(struct s_data *, char **, int, int);
  char			**maze;
  char			end;
  t_cell		*root;
}			t_data;


/*
** misc.c
*/

void			my_bzero(void *ptr, int size, char c);
int			my_getnbr(char *str);
void			my_put_error(const char *str);
void			my_put_usage(char **av);

/*
** check_corners.c
*/

int			how_many_stars_in_corner_nw(t_data *data,
						    char **maze,
						    int x, int y);
int			how_many_stars_in_corner_ne(t_data *data,
						    char **maze,
						    int x, int y);
int			how_many_stars_in_corner_sw(t_data *data,
						    char **maze,
						    int x, int y);
int			how_many_stars_in_corner_se(t_data *data,
						    char **maze,
						    int x, int y);
/*
** go.c
*/

int			north(t_data *data, t_cell *cur);
int			east(t_data *data, t_cell *cur);
int			south(t_data *data, t_cell *cur);
int			west(t_data *data, t_cell *cur);
int			choose_random_cell(t_data *data, t_cell *cell);

/*
** imperfect.c
*/

int			can_i_put_a_start(t_data *data, char **maze,
					  int x, int y);
void			go_to_imperfect_maze(t_data *data, char **maze);
int			get_loop(char **av);

/*
** perfect.c
*/

void			pop_one_cell(t_cell *root, char *go);
int			stack_one_cell(t_data *data, int x, int y,
				       int opdir);
int			add_cell(t_data *data, t_cell *cur,
				 int direction);
void			change_dir_end_cell(t_data *data, int dir);
int			go_to_perfect_maze(t_data *data);

/*
** init.c
*/

char			**generation(int width, int height);
void			init_tab_char(t_cell *cur);
int			init_root(t_data *data);

/*
** generate.c
*/

int			create_file(char **av);
int			count_path(t_cell *cur, int *dir);
int			write_maze_to_file(int fd, char **mazes);
int			generate_lab(char **av);

#endif /* !GENERATE_H_ */
