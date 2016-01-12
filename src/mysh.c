/*
** mysh.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Jan  5 14:02:14 2016 marc brout
** Last update Tue Jan 12 16:53:58 2016 marc brout
*/

#include "mysh.h"

char		set_pwd(t_arg *targ)
{
  int		i;
  int		nb;

  if ((i = find_env(targ->env, "PWD")) < 0)
    return (1);
  free(targ->env[i]);
  if ((targ->env[i] = malloc(1)) == NULL)
    return (1);
  targ->env[i][0] = 0;
  nb = 1;
  while (getcwd(targ->env[i], nb) == NULL && nb)
    targ->env[i] = my_realloc(targ->env[i], ++nb);
  if ((targ->env[i] = concat_str("PWD", '=', targ->env[i]))
      == NULL)
    return (1);
  return (0);
}

char		launch_mysh(t_arg *targ, char *str)
{
  int		status;
  t_builtins	test;

  if (!check_only_spaces(str))
    {
      if (!get_path(targ, targ->env))
	{
	  targ->pid = getpid();
	  targ->cpid = fork();
	  if (!targ->cpid)
	    execve(targ->wtab[0], targ->wtab, targ->env);
	  wait(&status);
	}
    }
  return (0);
}

char		exec_command(t_big *big, char *str)
{
  t_pfu		*tmp;

  if ((big->targ->wtab = str_to_wordtab(str, ' ')) == NULL)
    return (1);
  tmp = big->pfunc;
  while (tmp->next != NULL && my_strcmp(tmp->str, big->targ->wtab[0]))
    tmp = tmp->next;
  if (tmp->pfu(big->targ, str))
    return (1);
  if (big->targ->env == NULL)
    {
      free(str);
      return (2);
    }
  if (set_pwd(big->targ))
    return (1);
  return (0);
}

char		mysh(t_big *big)
{
  char		*str;
  int		ret;

  write(1, "$> ", 3);
  signal(SIGINT, SIG_IGN);
  while ((str = get_next_line(0)))
    {
      if ((big->targ->ptab =
	   env_to_wordtab(big->targ->env, "PATH=", ':')) == NULL)
	return (1);
      if (my_strcmp(str, ""))
	{
	  if ((ret = exec_command(big, str)) == 1)
	    return (1);
	  else if (ret == 2)
	    return (0);
	}
      free(str);
      write(1, "$> ", 3);
    }
  return (0);
}

int		main(UNUSED int ac, UNUSED char **av, char **ev)
{
  t_big		big;
  t_arg		targ;

  if (ev == NULL)
    {
      my_printf("Missing environnement variables\n");
      return (1);
    }
  big.targ = &targ;
  if ((big.targ->env = copy_env(ev)) == NULL ||
      (fill_pfunc(&big)))
    return (1);
  if (mysh(&big))
    return (1);
  return (0);
}
