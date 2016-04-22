/*
** my_put_error.c for lib
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Apr 22 14:11:44 2016 marc brout
** Last update Fri Apr 22 14:12:49 2016 marc brout
*/

#include <unistd.h>
#include "my.h"

void		my_put_error(char *str)
{
  write(1, str, my_strlen(str));
}
