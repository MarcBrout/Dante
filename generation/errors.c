/*
** errors.c for dante in /home/brout_m/RENDU/CPE/dante
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Last update Tue Apr 26 13:21:25 2016 marc brout
** Last update Fri Apr 22 16:10:59 2016 benjamin duhieu
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

void		my_put_usage(char **av)
{
  write(2, "USAGE : ", 8);
  write(2, av[0], my_strlen(av[0]));
  write(2, " [WIDTH] [HEIGHT] [(optional) LOOP] [(optional) NAME].\n",
	55);
}
