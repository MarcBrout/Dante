/*
** errors.c for lemin in /home/brout_m/RENDU/CPE/CPE_2015_lemin
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Apr  1 16:10:59 2016 marc brout
** Last update Thu Apr  7 17:19:15 2016 marc brout
*/

#include <unistd.h>
#include "generate.h"

void		my_put_room_str(const char *file,
				const char *str)
{
  write(2, "Room : ", 7);
  write(2, file, my_strlen((char *)file));
  write(2, str, my_strlen((char *)str));
}

int		my_put_file_noaccess(const char *file,
				     int err)
{
  write(2, "File ", 5);
  write(2, file, my_strlen((char *)file));
  write(2, " not accessible\n", 16);
  return (err);
}

void		my_put_error(const char *str)
{
  write(2, str, my_strlen((char *)str));
}

void		my_put_usage(char **av)
{
  write(2, "USAGE : ", 8);
  write(2, av[0], my_strlen(av[0]));
  write(2, " < [WIDTH] [HEIGHT].\n", 21);
}
