/*
** get_next_line.c for gnl
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Jan  4 10:27:46 2016 marc brout
** Last update Sun Jan 24 21:33:33 2016 marc brout
*/

#include "get_next_line.h"

char		*my_realloc(char *str, int size)
{
  char		*tmp;
  int		i;

  if ((tmp = malloc(size + 1)) == NULL)
    return (NULL);
  i = -1;
  while (str[++i] && i < size)
    tmp[i] = str[i];
  while (i <= size)
    tmp[i++] = 0;
  if (str != NULL)
    free (str);
  return (tmp);
}

char		*get_last_buff(char *buff, int *ret, int *i, int *j)
{
  int		size;
  char		*str;

  if ((str = malloc(1)) == NULL || *ret == 0)
    return (NULL);
  str[0] = 0;
  size = 0;
  if (*i < READ_SIZE && *i != -1)
    while (buff[++*i] && buff[*i] != '\n' && (size += 1))
      {
	if ((str = my_realloc(str, size)) == NULL)
	  return (NULL);
	str[++*j] = buff[*i];
      }
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	buf[READ_SIZE + 1];
  static int	i = -1;
  static int	r = -1;
  char		*str;
  int		size;
  int		j;

  str = NULL;
  if ((fd < 0) || (j = -1) > 0 || READ_SIZE < 1 ||
      (str = get_last_buff(buf, &r, &i, &j)) == NULL || buf[i] == 10)
    return (str);
  size = j + 1;
  while (buf[i] != 10 && (r = read(fd, buf, READ_SIZE)) > 0 && (size += r))
    {
      buf[r] = 0;
      if ((str = my_realloc(str, size)) == NULL)
	return (NULL);
      i = -1;
      while (buf[++i] && buf[i] != '\n' && (str[++j] = buf[i]));
    }
  if (size)
    return (str);
  free(str);
  return (NULL);
}
