/*
** env.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Jan  7 16:22:00 2016 marc brout
** Last update Tue Jan 12 15:38:01 2016 marc brout
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

char		cd_home(t_arg *targ)
{
  int		i;
  char		*str2;

  if (targ->wtab[1] == NULL)
    {
      if ((i = find_env(targ->env, "PWD=")) < 0)
	return (1);
      free(targ->env[i]);
      if ((targ->env[i] =
	   concat_str("PWD", '=', get_flagss(targ->env, "HOME"))) == NULL ||
	  (str2 = get_flagss(targ->env, "PWD")) == NULL ||
	  chdir(str2) < 0)
	return (1);
      return (2);
    }
  return (0);
}

char		mysh_cd(t_arg *targ, UNUSED char *path)
{
  int		i;
  char		*str2;

  if ((i = cd_home(targ)) == 1)
    return (1);
  if (!access(targ->wtab[1], F_OK) && i != 2)
    {
      if (!access(targ->wtab[1], R_OK))
	{
	  if ((i = find_env(targ->env, "PWD=")) < 0)
	    return (1);
	  free(targ->env[i]);
	  if ((targ->env[i] = concat_str("PWD", '=', targ->wtab[1])) == NULL
	      || (str2 = get_flagss(targ->env, "PWD")) == NULL ||
	      chdir(str2) < 0)
	    return (1);
	}
      else
	write(2, "Error while accessing path, no right.\n", 39);
    }
  else if (i != 2)
    write(2, "No such file or directory.\n", 28);
  return (0);
}

char		mysh_quit(UNUSED t_arg *targ, UNUSED char *str)
{
  free_tab(targ->env);
  free_tab(targ->wtab);
  free_tab(targ->ptab);
  targ->env = NULL;
  write(1, "exit\n", 5);
  return (0);
}
