/*
** mysh.h for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Jan  5 11:10:26 2016 marc brout
** Last update Tue Jan  5 19:34:05 2016 marc brout
*/

#ifndef MYSH_H_
# define MYSH_H_

# ifndef UNUSED
#  define UNUSED(x) (void)x
# endif /* !UNUSED */

# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "my.h"
# include "get_next_line.h"

typedef struct		s_arg
{
  int			nbw;
  pid_t			pid;
  pid_t			cpid;
  char			**wtab;
}			t_arg;

char str_to_wordtab(char *, t_arg *);
char add_word_to_tab(char **, char *, int);
char mysh(char **);
int count_words(char *);

#endif /* !MYSH_H_ */ 
