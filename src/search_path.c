/*
** search_path.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Jan  5 18:50:28 2016 marc brout
** Last update Wed Jan  6 13:59:41 2016 marc brout
*/

#include "mysh.h"

char		get_path(t_arg *targ, char **ev)
{
  UNUSED(ev);
  if (access(targ->wtab[0], F_OK))
    {
      write(2, "command not found : ", 20);
      write(2, targ->wtab[0], my_strlen(targ->wtab[0]));
      write(2, "\n", 1);
      return (1);
    }
  else if (access(targ->wtab[0], X_OK))
    {
      write(2, "access required : ", 18);
      write(2, targ->wtab[0], my_strlen(targ->wtab[0]));
      write(2, "\n", 1);
      return (1);
    }
  return (0);
}
