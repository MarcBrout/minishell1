/*
** copy_tabs.c for mysh
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Jan  7 15:34:29 2016 marc brout
** Last update Thu Jan 21 10:13:33 2016 marc brout
*/

#include "mysh.h"

int		count_words(char *arg, char c)
{
  int		i;
  int		nb;

  i = -1;
  nb = 0;
  while (arg[++i])
    if ((i > 0 && arg[i] != c && arg[i - 1] == c && arg[i] != 9 &&
	 arg[i] != 9) || (i == 0 && arg[i] != c && arg[i] != 9))
      nb += 1;
  return (nb);
}

char		**add_word_to_tab(char **wtab, char *arg, int nbw, char c)
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
      while ((arg[i] == c || arg[i] == 9) && arg[i] && (i += 1));
      k = i;
      while (arg[i] != c && arg[i] != 9 && arg[i] && (i += 1) && (j += 1));
      if ((wtab[m] = malloc(j + 1)) == NULL)
	return (NULL);
      l = 0;
      while (l < j)
	wtab[m][l++] = arg[k++];
      wtab[m][l] = 0;
    }
  return (wtab);
}

char		**str_to_wordtab(char *arg, char c)
{
  char		**tab;
  int		nbw;

  if ((nbw = count_words(arg, c)))
    {
      if ((tab = malloc(sizeof(char *) * (nbw + 1))) == NULL)
	return (NULL);
      tab[nbw] = NULL;
      return (add_word_to_tab(tab, arg, nbw, c));
    }
  return (NULL);
}

char		*copy_str(char *str)
{
  char		*cpy;
  int		let;
  int		i;

  let = my_strlen(str);
  if ((cpy = malloc(let + 1)) == NULL)
    return (NULL);
  cpy[let] = 0;
  i = -1;
  while (++i < let)
    cpy[i] = str[i];
  return (cpy);
}

char		**copy_env(char **env)
{
  int		nbl;
  int		i;
  char		**cpy;

  nbl = -1;
  while (env[++nbl] != NULL);
  if ((cpy = malloc(sizeof(char *) * (nbl + 1))) == NULL)
    return (NULL);
  cpy[nbl] = NULL;
  i = -1;
  while (++i < nbl)
    if ((cpy[i] = copy_str(env[i])) == NULL)
      return (NULL);
  return (cpy);
}
