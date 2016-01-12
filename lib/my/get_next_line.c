/*
** get_next_line.c for gnl
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Jan  4 10:27:46 2016 marc brout
** Last update Fri Jan  8 10:32:05 2016 marc brout
*/

#include "get_next_line.h"

int		gnl_len(char *str)
{
  int		i;

  i = -1;
  while (str[++i]);
  return (i);
}

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

char		*get_last_buff(char *buff, char *str, int *i, int *j)
{
  int		size;

  if ((str = malloc(1)) == NULL)
    return (NULL);
  str[0] = 0;
  size = 0;
  if (*i < READ_SIZE && *i != -1)
    while (buff[++*i] && buff[*i] != '\n' && (size++))
      {
	if ((str = my_realloc(str, size)) == NULL)
	  return (NULL);
	str[++*j] = buff[*i];
      }
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1];
  static int	i = -1;
  int		r;
  char		*str;
  int		size;
  int		j;

  j = -1;
  if ((str = get_last_buff(buff, str, &i, &j)) == NULL)
    return (NULL);
  if (buff[i] == '\n')
    return (str);
  size = gnl_len(str);
  while (buff[i] != 10 && (r = read(fd, buff, READ_SIZE)) > 0 && (size += r))
    {
      buff[r] = 0;
      if ((str = my_realloc(str, size)) == NULL)
	return (NULL);
      i = -1;
      while (buff[++i] && buff[i] != '\n' && (str[++j] = buff[i]));
    }
  if (size)
    return (str);
  free(str);
  return (NULL);
}
