/*
** env_suite.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Jan 11 19:43:15 2016 marc brout
** Last update Fri Jan 29 01:47:08 2016 marc brout
*/

#include "mysh.h"

char		**add_env(char **env, char *str, char c, char *str2)
{
  int		nbl;
  int		i;
  char		**cpy;

  nbl = -1;
  while (env[++nbl] != NULL);
  if ((cpy = malloc(sizeof(char *) * (nbl + 2))) == NULL)
    return (NULL);
  i = -1;
  while (++i < nbl && (cpy[i] = env[i]));
  if ((cpy[i] = concat_str(str, c, str2)) == NULL)
    return (NULL);
  cpy[++i] = NULL;
  free(env);
  return (cpy);
}

char		mysh_setenv(t_arg *targ, char *str)
{
  int		i;
  int		nb;

  if ((nb = count_arg(targ->wtab)) > 1 && nb < 3)
    {
      i = -1;
      while (targ->env[++i] && my_strncmp(targ->env[i], targ->wtab[1], my_strlen
					  (targ->wtab[1]) - 1));
      if (targ->env[i])
	{
	  free(targ->env[i]);
	  if (!(targ->env[i] = concat_str(targ->wtab[1], '=', targ->wtab[2])))
	    return (1);
	}
      else
	if (!(targ->env = add_env(targ->env, targ->wtab[1], '=', targ->wtab[2])))
	  return (1);
    }
  else if (nb > 3)
    write(2, "setenv: Too many arguments.\n", 29);
  else
    print_env(targ, str);
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
  cpy[++j] = NULL;
  free(targ->env);
  targ->env = cpy;
  return (0);
}

char		mysh_unsetenv(t_arg *targ, UNUSED char *str)
{
  int		i;
  int		j;
  int		nb;

  j = 0;
  while (targ->wtab[++j] != NULL)
    {
      i = 0;
      nb = my_strlen(targ->wtab[j]);
      while (targ->env[i] != NULL)
	{
	  if (!my_strncmp(targ->env[i], targ->wtab[j], nb - 1) &&
	      targ->env[i][nb] == '=')
	    break;
	  i += 1;
	}
      if (targ->env[i] != NULL)
	if (sub_env(targ, targ->env[i]))
	  return (1);
    }
  if (!targ->wtab[1])
    write(2, "unsetenv: Too few argments.\n", 29);
  return (0);
}
