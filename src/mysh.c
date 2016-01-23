/*
** mysh.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Jan  5 14:02:14 2016 marc brout
** Last update Sat Jan 23 23:17:28 2016 marc brout
*/

#include "mysh.h"

char		set_pwd(t_arg *targ)
{
  int		i;
  char		*str;
  int		nb;

  if ((i = find_env(targ->env, "PWD")) < 0)
    return (0);
  free(targ->env[i]);
  if ((str = malloc(1)) == NULL)
    return (1);
  str[0] = 0;
  nb = 1;
  while (getcwd(str, nb) == NULL && nb)
    str = my_realloc(str, ++nb);
  if ((targ->env[i] = concat_str("PWD", '=', str)) == NULL)
    return (1);
  free(str);
  return (0);
}

char		launch_mysh(t_arg *targ, char *str)
{
  int		status;

  if (!check_only_spaces(str))
    {
      if (!get_path(targ, targ->env))
	{
	  targ->pid = getpid();
	  targ->cpid = fork();
	  if (!targ->cpid)
	    if (execve(targ->wtab[0], targ->wtab, targ->env) < 0)
	      {
		write(2, "Error while executing file.\n", 29);
		free_tab(targ->env);
		free_tab(targ->wtab);
		free_tab(targ->ptab);
		exit(1);
	      }
	  wait(&status);
	  if (WIFSIGNALED(status))
	    write(2, "Segmentation fault\n", 20);
	}
    }
  return (0);
}

char		exec_command(t_big *big, char *str)
{
  t_pfu		*tmp;
  int		nb;

  if ((big->targ->wtab = str_to_wordtab(str, ' ')) != NULL)
    {
      tmp = big->pfunc;
      while (tmp->next != NULL && my_strcmp(tmp->str, big->targ->wtab[0]))
	tmp = tmp->next;
      if ((nb = tmp->pfu(big->targ, str)) == 1)
	  return (1);
      if (big->targ->env == NULL)
	{
	  free_list(big->pfunc);
	  free(str);
	  return (nb);
	}
      if (set_pwd(big->targ))
	return (1);
      free_tab(big->targ->wtab);
    }
  return (0);
}

char		mysh(t_big *big)
{
  char		*str;
  int		ret;

  write(1, "$> ", 3);
  signal(SIGINT, SIG_IGN);
  if (find_env(big->targ->env, "PATH=") < 0)
    if ((big->targ->env = add_env
	 (big->targ->env, "PATH", '=', "/bin:/usr/bin:/usr/local/bin"))
	== NULL)
      return (1);
  if ((big->targ->ptab =
       env_to_wordtab(big->targ->env, "PATH=", ':')) == NULL)
    return (1);
  while ((str = get_next_line(0)))
    {
      if (my_strcmp(str, ""))
	if ((ret = exec_command(big, str)) >= 1 || big->targ->env == NULL)
	  return (ret);
      free(str);
      write(1, "$> ", 3);
    }
  return (0);
}

int		main(UNUSED int ac, UNUSED char **av, char **ev)
{
  t_big		big;
  t_arg		targ;

  big.targ = &targ;
  targ.pwd = NULL;
  if (ev[0] == NULL)
    {
      if ((big.targ->env = def_env()) == NULL)
	return (1);
    }
  else if ((big.targ->env = copy_env(ev)) == NULL)
    return (1);
  if (fill_pfunc(&big))
    return (1);
  return (mysh(&big));
}
