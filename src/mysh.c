/*
** mysh.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Jan  5 14:02:14 2016 marc brout
** Last update Thu Jan  7 18:50:44 2016 marc brout
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

char		launch_mysh(t_arg *targ, char *str)
{
  int		status;
  
  if (!check_only_spaces(str))
    {
      if ((targ->wtab = str_to_wordtab(str, ' ')) == NULL)
	return (1);
      if ((targ->ptab = env_to_wordtab(targ->env, "PATH=", ':')) == NULL)
	return (1);
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

char		mysh(t_big *big)
{
  char		*str;
  t_pfu		*tmp;

  write(1, "$> ", 3);
  while ((str = get_next_line(0)))
    {
      if (my_strcmp(str, ""))
	{
	  tmp = big->pfunc;
	  while (tmp->next != NULL && my_strcmp(tmp->str, str))
	    tmp = tmp->next;
	  if (tmp->pfu(big->targ, str))
	    return (1);
	}
      free(str);
      write(1, "$> ", 3);
    }
  return (0);
}

int		main(int ac, char **av, char **ev)
{
  t_big		big;
  t_arg		targ;

  UNUSED(ac);
  UNUSED(av);
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
