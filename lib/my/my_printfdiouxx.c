/*
** my_prinfdioux.c for my_print_f
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Nov  4 13:26:29 2015 marc brout
** Last update Tue Nov 17 13:52:39 2015 marc brout
*/

#include "my.h"

int	my_print_d(va_list ap, char c, const char *str, int pos)
{
  int	count;
  int	nb;

  nb = (long int)va_arg(ap, int);
  count = 0;
  if (nb < 0 && str[pos - 1] == ' ')
    {
      my_putchar('\b');
      count--;
    }
  if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      return (11);
    }
  if (nb < 0)
    {
      count++;
      my_putchar('-');
      nb = -nb;
    }
  count += my_printf_nbr(nb);
  return (count);
}

int	my_print_u(va_list ap, char c, const char *str, int pos)
{
  return (my_putnbr_base_un(va_arg(ap, unsigned int), "0123456789"));
}

int	my_print_o(va_list ap, char c, const char *str, int pos)
{
  return (my_putnbr_base_un(va_arg(ap, unsigned int), "01234567"));
}

int	my_print_x(va_list ap, char c, const char *str, int pos)
{
  return (my_putnbr_base_un(va_arg(ap, unsigned int), "0123456789abcdef"));
}

int	my_print_x2(va_list ap, char c, const char *str, int pos)
{
  return (my_putnbr_base_un(va_arg(ap, unsigned int), "0123456789ABCDEF"));
}
