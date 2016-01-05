/*
** my_printfcsspb.c for printf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Nov  4 16:57:46 2015 marc brout
** Last update Tue Nov 17 13:34:14 2015 marc brout
*/

#include "my.h"

int	my_print_c(va_list ap, char c, const char *str, int pos)
{
  my_putchar((unsigned char) va_arg(ap, int));
  return (1);
}

int	my_print_s(va_list ap, char c, const char *st, int pos)
{
  char	*str;
  int	i;

  str = va_arg(ap, char *);
  i = 0;
  if (str == NULL)
    {
      my_putstr("(null)");
      return (6);
    }
  while (str[i])
    my_putchar(str[i++]);
  return (i);
}

int	my_print_s2(va_list ap, char c, const char *st, int pos)
{
  char	*str;
  int	i;
  int	tot;
  int	prec;

  str = va_arg(ap, char *);
  if (str == NULL)
    {
      my_putstr("(null)");
      return (6);
    }
  i = 0;
  tot = 0;
  while (str[i])
    {
      prec = tot;
      if ((tot += check_octal((unsigned char) str[i])) > prec)
	tot += put_octal((unsigned char) str[i++]);
      my_putchar(str[i++]);
      tot++;
    }
  return (tot);
}

int		my_print_p(va_list ap, char c, const char *str, int pos)
{
  void		**ptr;
  int		count;

  if ((ptr = malloc(sizeof(void *))) == NULL)
    return (-1);
  ptr[0] = va_arg(ap, void *);
  if (ptr[0] == 0)
    {
      my_putstr("(nil)");
      return (5);
    }
  else
    {
      my_putstr("0x");
      count = my_putnbr_base_lo((unsigned long) ptr[0], "0123456789abcdef");
      count += 2;
    }
  if (ptr != NULL)
    free(ptr);
  return (count);
}

int	my_print_b(va_list ap, char c, const char *str, int pos)
{
  return (my_putnbr_base_un(va_arg(ap,unsigned int), "01"));
}
