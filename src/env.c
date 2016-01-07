/*
** env.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Jan  7 16:22:00 2016 marc brout
** Last update Thu Jan  7 18:26:14 2016 marc brout
*/

#include "mysh.h"

char		print_env(t_arg *targ, char *str)
{
  int		i;
  
  UNUSED(str);
  i = -1;
  while (targ->env[++i] != NULL)
    printf("%s\n", targ->env[i]);
  return (0);
}

char		mysh_setenv(t_arg *targ, char *str)
{
  UNUSED(targ);
  UNUSED(str);
  return (0);
}

char		mysh_unsetenv(t_arg *targ, char *str)
{
  UNUSED(targ);
  UNUSED(str);
  return (0);
}

char		mysh_cd(t_arg *targ, char *str)
{
  UNUSED(targ);
  UNUSED(str);
  return (0);
}

char		mysh_quit(t_arg *targ, char *str)
{
  UNUSED(targ);
  UNUSED(str);
  return (1);
}
