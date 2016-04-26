/*
** errors.c for dante in /home/brout_m/RENDU/CPE/dante
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Apr 26 13:06:36 2016 marc brout
** Last update Tue Apr 26 13:16:54 2016 marc brout
*/

#include <unistd.h>
#include "my.h"

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

int		my_put_usage(char **av, int err)
{
  write(2, "USAGE : ", 8);
  write(2, av[0], my_strlen(av[0]));
  write(2, " [WIDTH] [HEIGHT] [(optional) LOOP] [(optional) NAME].\n",
	55);
  return (err);
}
