/*
** search_path.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Jan  5 18:50:28 2016 marc brout
** Last update Mon Jan 11 19:18:33 2016 marc brout
*/

#include "mysh.h"

char		get_path(t_arg *targ, UNUSED char **ev)
{
  if (find_path(targ))
    {
      write(2, "command not found.\n", 20);
      return (1);
    }
  else if (access(targ->wtab[0], X_OK))
    {
      write(2, "access required.\n", 18);
      return (1);
    }
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
  int		k;

  k = -1;
  str = targ->wtab[0];
  while (access(str, F_OK) && targ->ptab[++k] != NULL)
    {
      if ((str = concat_str(targ->ptab[k], '/', targ->wtab[0])) == NULL)
	return (1);
      free(targ->wtab[0]);
      targ->wtab[0] = str;
    }
  if (targ->ptab[k] == NULL)
    return (1);
  return (0);
}
