/*
** my_getnbr.c for my_getnbr.c in /home/brout_m/rendu/Piscine_C_J10
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct 12 19:01:57 2015 marc brout
** Last update Sat Oct 17 10:17:03 2015 marc brout
*/

int		my_getnbr(char *str)
{
  unsigned int	total;
  int		isneg;
  int		i;

  i = 0;
  isneg = 1;
  while ((str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '-')
	isneg = -isneg;
      i = i + 1;
    }
  total = 0;
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      if (((total * 10) + (str[i] - 48)) > 2147483647)
	return (0);
      total = ((total * 10) + (str[i] - 48));
      i = i + 1;
    }
  return (total * isneg);
}
