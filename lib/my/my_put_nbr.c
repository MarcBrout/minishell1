/*
** my_put_nbr.c for my_put_nbr in ~/rendu/Piscine_C_J10
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct 12 19:37:45 2015 marc brout
** Last update Sat Oct 17 22:59:13 2015 marc brout
*/

int	my_put_nbr(int nb)
{
  int	unit;
  int	power;
  int	stock;

  power = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  stock = nb;
  while ((nb / 10) > 0)
    {
      power = power * 10;
      nb = nb / 10;
    }
  while ((power / 10) > 0)
    {
      my_putchar((stock / power) + 48);
      stock = stock - ((stock / power) * power);
      power = power / 10;
    }
  my_putchar((stock % 10) + 48);
  return (0);
}
