/*
** search_path.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Jan  5 18:50:28 2016 marc brout
** Last update Sun Jan 24 17:42:00 2016 marc brout
*/

#include "mysh.h"

char		get_path(t_arg *targ, UNUSED char **ev)
{
  char		*tmp;

  tmp = my_strdup(targ->wtab[0]);
  if (find_path(targ))
    {
      write(2, tmp, my_strlen(tmp));
      write(2, ": Command not found.\n", 22);
      free(tmp);
      return (1);
    }
  else if (access(targ->wtab[0], X_OK))
    {
      write(2, "access required.\n", 18);
      free(tmp);
      return (1);
    }
  free(tmp);
  return (0);
}

char		**env_to_wordtab(char **ev, char *str, char c)
{
  int		i;

  i = 0;
  while (ev[i] != NULL && my_strncmp(ev[i], str, my_strlen(str) - 1))
    i += 1;
  return (str_to_wordtab(&ev[i][my_strlen(str)], c));
}

char		find_path(t_arg *targ)
{
  char		*str;
  char		*tmp;
  int		k;
  int		i;

  k = 0;
  if ((tmp = my_strdup(targ->wtab[0])) == NULL ||
      (str = targ->wtab[0]) == NULL)
    return (1);
  while (access(str, F_OK) && targ->ptab != NULL && targ->ptab[k] != NULL)
    {
      if ((str = concat_str(targ->ptab[k], '/', tmp)) == NULL)
	return (1);
      i = -1;
      while (str[++i] && str[i + 1])
	if ((str[i] == '/' || str[i] == '.') && str[i + 1] == '/')
	  return (1);
      free(targ->wtab[0]);
      targ->wtab[0] = str;
      k += 1;
    }
  free(tmp);
  if (access(str, F_OK) && (targ->ptab == NULL || targ->ptab[k] == NULL))
    return (1);
  return (0);
}

int		count_arg(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i]);
  return (i);
}
