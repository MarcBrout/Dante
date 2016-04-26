/*
** my_error.c for my in /home/brout_m/RENDU/CPE/dante
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Apr 26 13:11:32 2016 marc brout
** Last update Tue Apr 26 13:13:32 2016 marc brout
*/

#include <unistd.h>
#include "my.h"

void	my_put_error(char *str)
{
  write(2, str, my_strlen(str));
}
