/*
** my_printfmetc.c
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sun Nov  8 15:35:05 2015 marc brout
** Last update Tue Nov 17 13:33:48 2015 marc brout
*/

#include "my.h"

int	my_print_etc(va_list ap, char c, const char *str, int i)
{
  my_putchar(c);
  return (1);
}

int	my_print_pcent(va_list ap, char c, const char *str, int i)
{
  my_putchar('%');
  return (1);
}

int	my_check_empty(const char *str, int i)
{
  i = i + 1;
  while (str[i] == ' ' && str[i])
    i++;
  if (str[i] == 0)
    return (1);
  return (0);
}

int	my_prints(const char *str, int *i)
{
  int	count;

  count = 0;
  *i = *i + 1;
  while (str[*i] == ' ')
    *i = *i + 1;
  if (str[*i - 1] == ' ' &&
      (str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'p'))
    {
      my_putchar(' ');
      count++;
    }
  else if (get_flag(str[*i]) == 12)
    {
      my_putchar('%');
      count ++;
      if (str[*i - 1] == ' ')
	{
	  my_putchar(' ');
	  count++;
	}
    }
  return (count);
}

int		my_printf_nbr(int nb)
{
  int		power;
  int		stock;
  int		len;

  power = 1;
  len = 1;
  stock = nb;
  while ((nb / 10) > 0)
    {
      power *= 10;
      nb /= 10;
      len++;
    }
  while ((power / 10) > 0)
    {
      my_putchar((stock / power) + 48);
      stock -= (stock / power) * power;
      power /= 10;
    }
  my_putchar((stock % 10) + 48);
  return (len);
}
