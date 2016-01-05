/*
** my_strlen.c for my_strlen in /home/brout_m/dev/PJ4
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Oct  1 16:44:35 2015 marc brout
** Last update Sat Oct 17 10:07:26 2015 marc brout
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}
