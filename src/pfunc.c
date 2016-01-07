/*
** pfunc.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Jan  7 17:07:09 2016 marc brout
** Last update Thu Jan  7 18:41:35 2016 marc brout
*/

#include "mysh.h"

char		add_elem(t_big *big, char *str, func pfu)
{
  t_pfu		*elem;
  t_pfu		*tmp;

  tmp = big->pfunc;
  while (tmp->next != NULL)
    tmp = tmp->next;
  if ((elem = malloc(sizeof(t_pfu))) == NULL)
    return (1);
  elem->str = str;
  elem->pfu = pfu;
  elem->next = NULL;
  tmp->next = elem;
  return (0);
}

char		fill_pfunc(t_big *big)
{
  if ((big->pfunc = malloc(sizeof(t_pfu))) == NULL)
    return (1);
  big->pfunc->next = NULL;
  big->pfunc->str = "exit";
  big->pfunc->pfu = &mysh_quit;
  if (add_elem(big, "env", print_env) ||
      add_elem(big, "setenv", mysh_setenv) ||
      add_elem(big, "unsetenv", mysh_unsetenv) ||
      add_elem(big, "cd", mysh_cd) ||
      add_elem(big, "last", launch_mysh))
    return (1);
  return (0);
}
