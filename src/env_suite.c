/*
** env_suite.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Jan 11 19:43:15 2016 marc brout
** Last update Mon Jan 11 19:51:00 2016 marc brout
*/

#include "mysh.h"

char		add_env(t_arg *targ)
{
  int		nbl;
  int		i;
  char		**cpy;

  nbl = -1;
  while (targ->env[++nbl] != NULL);
  if ((cpy = malloc(sizeof(char *) * (nbl + 2))) == NULL)
    return (1);
  i = -1;
  while (++i < nbl && (cpy[i] = targ->env[i]));
  if ((cpy[i] = concat_str(targ->wtab[1], '=', targ->wtab[2])) == NULL)
    return (1);
  cpy[++i] = NULL;
  free(targ->env);
  targ->env = cpy;
  return (0);
}

char		mysh_setenv(t_arg *targ, UNUSED char *str)
{
  int		i;

  if (targ->wtab[1] != NULL && targ->wtab[2] != NULL)
    {
      i = -1;
      while (targ->env[++i] != NULL &&
	     my_strncmp(targ->env[i], targ->wtab[1],
			my_strlen(targ->wtab[1]) - 1));
      if (targ->env[i] != NULL)
	{
	  free(targ->env[i]);
	  if ((targ->env[i] = concat_str(targ->wtab[1], '=', targ->wtab[2]))
	      == NULL)
	    return (1);
	}
      else
	return (add_env(targ));
    }
  else
    write(1, "Usage : setenv [FLAG] [value]\n", 31);
  return (0);
}

char		sub_env(t_arg *targ, char *str)
{
  char		**cpy;
  int		nbl;
  int		i;
  int		j;

  nbl = -1;
  while (targ->env[++nbl] != NULL);
  if ((cpy = malloc(sizeof(char *) * nbl)) == NULL)
    return (1);
  i = -1;
  j = -1;
  while (++i < nbl)
    if (my_strcmp(targ->env[i], str))
      cpy[++j] = targ->env[i];
  cpy[j] = NULL;
  free(targ->env);
  targ->env = cpy;
  return (0);
}

char		mysh_unsetenv(t_arg *targ, UNUSED char *str)
{
  int		i;

  if (targ->wtab[1] != NULL)
    {
      i = -1;
      while (targ->env[++i] != NULL &&
	     my_strncmp(targ->env[i], targ->wtab[1],
			my_strlen(targ->wtab[1]) - 1));
      if (targ->env[i] != NULL)
	if (sub_env(targ, targ->env[i]))
	  return (1);
    }
  else
    write(1, "Usage : unsetenv [FLAG]\n", 25);
  return (0);
}
