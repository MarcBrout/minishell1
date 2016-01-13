/*
** env.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Jan  7 16:22:00 2016 marc brout
** Last update Wed Jan 13 02:47:09 2016 marc brout
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
  char		*str;
  char		*str2;
  char		*str3;

  if (targ->wtab[1] == NULL || !my_strncmp(targ->wtab[1], "~", 1))
    {
      if ((i = find_env(targ->env, "PWD=")) < 0)
	return (1);
      str = targ->env[i];
      if ((str3 = get_flagss(targ->env, "HOME")) == NULL ||
	  (targ->env[i] = concat_str("PWD", '=', str3)) == NULL ||
	  (str2 = get_flagss(targ->env, "PWD")) == NULL || chdir(str2) < 0)
	return (1);
      free(str3);
      free(str2);
      free(str);
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
  if (i != 2 && !access(targ->wtab[1], F_OK))
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
	  free(str2);
	}
      else
	write(2, "Error while accessing path, no right.\n", 39);
    }
  else if (i != 2)
    write(2, "No such file or directory.\n", 28);
  return (0);
}

char		mysh_quit(t_arg *targ, UNUSED char *str)
{
  int		nb;

  nb = (targ->wtab[1] != NULL) ? my_getnbr(targ->wtab[1]) : 0;
  free_tab(targ->env);
  free_tab(targ->wtab);
  free_tab(targ->ptab);
  targ->env = NULL;
  write(1, "exit\n", 5);
  return (nb);
}
