/*
** my_putstr.c for my_putstr in /home/brout_m/dev/PJ4
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Oct  1 13:17:19 2015 marc brout
** Last update Fri Oct 16 14:41:59 2015 marc brout
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
