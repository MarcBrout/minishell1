/*
** my_strcmp.c for my_strcmp in /home/brout_m/dev/piscine/PJ6
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct  5 14:42:02 2015 marc brout
** Last update Fri Jan  8 16:19:42 2016 marc brout
*/

int	my_strncmp(char *need, char *tar, int n)
{
  int	i;

  i = 0;
  while ((tar[i]) && (need[i]) && (tar[i] == need[i]) && i < n)
    i = i + 1;
  return (need[i] - tar[i]);
}

