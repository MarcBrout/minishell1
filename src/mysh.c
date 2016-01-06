/*
** mysh.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Jan  5 14:02:14 2016 marc brout
** Last update Wed Jan  6 14:27:41 2016 marc brout
*/

#include "mysh.h"

int		count_words(char *arg)
{
  int		i;
  int		nb;

  i = -1;
  nb = 0;
  while (arg[++i])
    {
      if (i > 0 && arg[i] != ' ' && arg[i - 1] == ' ')
	nb += 1;
      if (i == 0 && arg[i] != ' ')
	nb += 1;
    }
  return (nb);
}

char		add_word_to_tab(char **wtab, char *arg, int nbw)
{
  int		i;
  int		j;
  int		k;
  int		l;
  int		m;

  i = 0;
  m = -1;
  while (++m < nbw)
    {
      j = 0;
      while (arg[i] == ' ' && arg[i] && (i += 1));
      k = i;
      while (arg[i] != ' ' && arg[i] && (i += 1) && (j += 1));
      if ((wtab[m] = malloc(j + 1)) == NULL)
	return (1);
      l = 0;
      while (l < j)
	wtab[m][l++] = arg[k++];
      wtab[m][l] = 0;
    }
  return (0);
}

char		str_to_wortab(char *arg, t_arg *targ)
{
  int		nbw;

  if ((nbw = count_words(arg)))
    {
      if ((targ->wtab = malloc(sizeof(char *) * (nbw + 1))) == NULL)
	return (1);
      targ->wtab[nbw] = NULL;
      if (add_word_to_tab(targ->wtab, arg, nbw))
	return (1);
    }
  return (0);
}

char		mysh(char **ev)
{
  t_arg		targ;
  int		status;
  char		*str;

  write(1, "$> ", 3);
  while ((str = get_next_line(0)))
    {
      if (!my_strcmp(str, "exit"))
	return (0);
      if (my_strcmp(str, ""))
	{
	  if (str_to_wortab(str, &targ))
	    return (1);
	  if (!get_path(&targ, ev))
	    {
	      targ.pid = getpid();
	      targ.cpid = fork();
	      if (!targ.cpid)
		execve(targ.wtab[0], &targ.wtab[1], ev);
	      else
		wait(&status);
	    }
	}
      free(str);
      write(1, "$> ", 3);
    }
  return (0);
}

int		main(int ac, char **av, char **ev)
{
  int		i;

  UNUSED(ac);
  UNUSED(av);
  if (ev == NULL)
    {
      my_printf("Missing environnement variables\n");
      return (1);
    }
  i = -1;
  while (ev[++i] != NULL)
    printf("%s\n", ev[i]);
  if (mysh(ev))
    return (1);
  return (0);
}
