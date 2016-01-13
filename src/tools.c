/*
** tools.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Jan 11 19:41:00 2016 marc brout
** Last update Wed Jan 13 04:05:10 2016 marc brout
*/

#include "mysh.h"

char		check_only_spaces(char *str)
{
  int		i;

  i = -1;
  while (str[++i] == ' ');
  if (str[i] == 0)
    return (1);
  return (0);
}

char		*concat_str(char *str1, char c, char *str2)
{
  char		*end;
  int		i;
  int		j;

  if (str1 == NULL || str2 == NULL ||
      (end = malloc(my_strlen(str1) + my_strlen(str2) + 2)) == NULL)
    return (NULL);
  i = -1;
  j = -1;
  while (str1[++i] && (end[++j] = str1[i]));
  end[++j] = c;
  i = -1;
  while (str2[++i] && (end[++j] = str2[i]));
  end[++j] = 0;
  return (end);
}

char		*get_flagss(char **env, char *str)
{
  char		*ret;
  int		i;
  int		j;
  int		k;

  i = -1;
  while (env[++i] != NULL &&
	 my_strncmp(env[i], str, my_strlen(str) - 1));
  if (env[i] != NULL)
    {
      j = my_strlen(str);
      while (env[i][++j]);
      if ((ret = malloc(j + 1)) == NULL)
	return (NULL);
      j = my_strlen(str);
      k = -1;
      while (env[i][++j] && (ret[++k] = env[i][j]));
      ret[++k] = 0;
    }
  else
    return (NULL);
  return (ret);
}

int		find_env(char **env, char *flag)
{
  int		i;

  i = -1;
  while (env[++i] != NULL &&
	 my_strncmp(env[i], flag, my_strlen(flag) - 1));
  if (env[i] == NULL)
    return (-1);
  return (i);
}
