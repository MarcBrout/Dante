/*
** random.c for dante in /home/brout_m/RENDU/CPE/dante
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Apr 26 14:00:54 2016 marc brout
** Last update Tue Apr 26 14:12:03 2016 marc brout
*/

int	my_rand()
{
  g_next = g_next * 1103515245 + 12345;
  return ((unsigned)(g_next / 65536) % 32768);
}
