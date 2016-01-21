/*
** env.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Jan  7 16:22:00 2016 marc brout
** Last update Thu Jan 21 16:14:47 2016 marc brout
*/

#include "mysh.h"

char		print_env(t_arg *targ, UNUSED char *str)
{
  int		i;

  i = -1;
  while (targ->env[++i] != NULL)
    my_printf("%s\n", targ->env[i]);
  return (0);
}

char		cd_tiret(t_arg *targ)
{
  char		*tmp;
  int		i;

  if (targ->wtab[1] != NULL &&
      !my_strncmp(targ->wtab[1], "-", 1) && targ->pwd != NULL)
    {
      tmp = targ->pwd;
      if ((i = find_env(targ->env, "PWD=")) < 0)
	if ((targ->env = add_env(targ->env, "PWD", '=', "/")) == NULL)
	  return (1);
      if ((targ->pwd = get_flagss(targ->env, "PWD")) == NULL)
	return (1);
      free(targ->env[i]);
      if ((targ->env[i] = concat_str("PWD", '=', tmp)) == NULL ||
	  chdir(tmp) < 0)
	return (1);
      return (2);
    }
  return (cd_home(targ));
}

char		cd_home(t_arg *targ)
{
  int		i;
  char		*str3;

  if (targ->wtab[1] == NULL)
    {
      if ((i = find_env(targ->env, "PWD=")) < 0)
	if ((targ->env = add_env(targ->env, "PWD", '=', "/")) == NULL)
	  return (1);
      if ((i = find_env(targ->env, "HOME=")) < 0)
	if ((targ->env = add_env(targ->env, "HOME", '=', "/")) == NULL)
	  return (1);
      if ((targ->pwd = get_flagss(targ->env, "PWD")) == NULL ||
	  (i = find_env(targ->env, "PWD=")) < 0)
	return (1);
      if ((str3 = get_flagss(targ->env, "HOME")) == NULL ||
	  (targ->env[i] = concat_str("PWD", '=', str3)) == NULL ||
	  (chdir(str3) < 0))
	return (1);
      free(str3);
      return (2);
    }
  return (0);
}

char		mysh_cd(t_arg *targ, UNUSED char *path)
{
  int		i;

  if ((i = cd_tiret(targ)) == 1)
    return (1);
  if (i != 2 && !access(targ->wtab[1], F_OK))
    {
      if (!access(targ->wtab[1], R_OK))
	{
	  if ((i = find_env(targ->env, "PWD=")) < 0)
	    if ((targ->env = add_env(targ->env, "PWD", '=', "/")) == NULL)
	      return (1);
	  if ((targ->pwd = get_flagss(targ->env,"PWD")) == NULL ||
	      ((i = find_env(targ->env, "PWD=")) < 0))
	    return (1);
	  free(targ->env[i]);
	  if ((targ->env[i] = concat_str("PWD", '=', targ->wtab[1])) == NULL
	      || chdir(targ->wtab[1]) < 0)
	    return (1);
	}
      else
	write(2, "Error while accessing path, no rights.\n", 40);
    }
  else if (i != 2)
    write(2, "No such file or directory.\n", 28);
  return (0);
}

char		mysh_quit(t_arg *targ, UNUSED char *str)
{
  int		nb;

  nb = (targ->wtab[1] != NULL) ? my_getnbr(targ->wtab[1]) : 0;
  if (targ->env != NULL)
    free_tab(targ->env);
  if (targ->wtab != NULL)
    free_tab(targ->wtab);
  if (targ->ptab != NULL)
    free_tab(targ->ptab);
  if (targ->pwd != NULL)
    free(targ->pwd);
  targ->env = NULL;
  write(1, "exit\n", 5);
  return (nb);
}
