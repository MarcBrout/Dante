/*
** my_bzero.c for lemin in ~/RENDU/CPE/CPE_2015_lemin/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Apr  1 16:38:37 2016 marc brout
** Last update Fri Apr  1 16:46:52 2016 marc brout
*/

void	my_bzero(void *var, int size, char val)
{
  int	i;
  char	*str;

  if (var)
    {
      i = 0;
      str = (char *)var;
      while (i < size)
	{
	  str[i] = val;
	  i += 1;
	}
    }
}
