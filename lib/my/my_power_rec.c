/*
** my_power_rec.c for my_power_rec in /home/brout_m/dev/PJ5
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Oct  2 11:57:05 2015 marc brout
** Last update Sun Oct 18 12:57:24 2015 marc brout
*/

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    return (1);
  if (power == 1)
    return (nb);
  power = power - 1;
  nb = nb * my_power_rec(nb, power);
}
