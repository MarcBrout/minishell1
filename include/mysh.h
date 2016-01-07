/*
** mysh.h for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Jan  5 11:10:26 2016 marc brout
** Last update Thu Jan  7 18:53:16 2016 marc brout
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
  pid_t			pid;
  pid_t			cpid;
  char			**wtab;
  char			**ptab;
  char			**env;
}			t_arg;

typedef char		(*func)(t_arg *, char *);

typedef struct		s_pfu
{
  char			*str;
  func			pfu;
  struct s_pfu		*next;
}			t_pfu;

typedef struct		s_big
{
  t_arg			*targ;
  t_pfu			*pfunc;
}			t_big;

char add_elem(t_big *, char *, func);
char fill_pfunc(t_big *);
char mysh_setenv(t_arg *, char *);
char mysh_unsetenv(t_arg *, char *);
char mysh_quit(t_arg *, char *);
char mysh_cd(t_arg *, char *);
char print_env(t_arg *, char *);
char launch_mysh(t_arg *, char *);
char find_path(t_arg *);
char get_path(t_arg *, char **);
char *copy_str(char *);
char **copy_env(char **);
char **str_to_wordtab(char *, char);
char **add_word_to_tab(char **, char *, int, char);
char **env_to_wordtab(char **, char *, char);
char mysh(t_big *);
int count_words(char *, char);

#endif /* !MYSH_H_ */
