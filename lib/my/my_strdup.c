/*
** my_strdup.c for my_strdup in /home/brout_m/dev/piscine/PJ8
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Oct  7 10:24:46 2015 marc brout
** Last update Tue Nov 17 13:33:28 2015 marc brout
*/

#include "my.h"

char	*my_strdup(char *src)
{
  int	i;
  char	*dest;

  i = 0;
  if ((dest = malloc(sizeof(char) * my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}

int		my_putnbr_base_un(unsigned int nb, char *base)
{
  unsigned int  stock;
  unsigned int	power;
  int		len;
  int		count;

  power = 1;
  count = 1;
  stock = nb;
  len = my_strlen(base);
  while ((nb / len) > 0)
    {
      power *= len;
      nb /= len;
      count++;
    }
  while ((power / len) > 0)
    {
      my_putchar(base[stock / power]);
      stock -= (stock / power) * power;
      power /= len;
    }
  my_putchar(base[stock % len]);
  return (count);
}

int		my_putnbr_base_lo(unsigned long nb, char *base)
{
  unsigned long stock;
  unsigned long	power;
  int		len;
  int		count;

  power = 1;
  count = 1;
  stock = nb;
  len = my_strlen(base);
  while ((nb / len) > 0)
    {
      power *= len;
      nb /= len;
      count++;
    }
  while ((power / len) > 0)
    {
      my_putchar(base[stock / power]);
      stock -= (stock / power) * power;
      power /= len;
    }
  my_putchar(base[stock % len]);
  return (count);
}
