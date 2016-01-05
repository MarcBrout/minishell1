/*
** my_printf.c for my_printf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Nov  3 14:56:06 2015 marc brout
** Last update Tue Nov 17 13:53:01 2015 marc brout
*/

#include "my.h"

int		my_printf(const char *f, ...)
{
  va_list	ap;
  t_ptrftab	ftab;
  char		*arg;
  int		i;
  int		len;

  len = 0;
  i = 0;
  ftab = init_myprintf_ftab();
  va_start(ap, f);
  while (f[i])
    {
      if (f[i] == '%')
	{
	  if (my_check_empty(f, i) > 0)
	    return (-1);
	  len += my_prints(f, &i) + ftab[get_flag(f[i])](ap, f[i++], f, i);
	}
      else if (len++)
	my_putchar(f[i++]);
    }
  if (free != NULL)
    free(ftab);
  va_end(ap);
  return (len);
}

int		get_flag(char c)
{
  char		*tab;
  int		i;

  i = 0;
  tab = my_strdup("diouxXcsSpb%");
  while (c != tab[i] && tab[i])
    i++;
  if (tab[i] = 0)
    return (12);
  if (tab != NULL)
    free(tab);
  return (i);
}

t_ptrftab	init_myprintf_ftab()
{
  t_ptrftab	ftab;

  if ((ftab = malloc(sizeof(int *) * 13)) == NULL)
    return (NULL);
  ftab[0] = &my_print_d;
  ftab[1] = &my_print_d;
  ftab[2] = &my_print_o;
  ftab[3] = &my_print_u;
  ftab[4] = &my_print_x;
  ftab[5] = &my_print_x2;
  ftab[6] = &my_print_c;
  ftab[7] = &my_print_s;
  ftab[8] = &my_print_s2;
  ftab[9] = &my_print_p;
  ftab[10] = &my_print_b;
  ftab[11] = &my_print_pcent;
  ftab[12] = &my_print_etc;
  return (ftab);
}

int	check_octal(unsigned char c)
{
  if (c < 8)
    {
      my_putstr("\\00");
      return (3);
    }
  if (c >= 8 && c < 32)
    {
      my_putstr("\\0");
      return (2);
    }
  if (c >= 127)
    {
      my_putstr("\\");
      return (1);
    }
  return (0);
}

int	put_octal(unsigned char c)
{
  int	nb;
  int	res;
  int	pi;

  res = 0;
  nb = 0;
  pi = 0;
  while ((c / 8) > 0)
    {
      res += (c % 8) * my_power_rec(10, pi);
      c /= 8;
      pi++;
    }
  res += (c % 8) * my_power_rec(10, pi);
  my_put_nbr(res);
  return (++pi);
}
