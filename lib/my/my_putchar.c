/*
** my_putchar.c for my_putchar in ~/dev/lib
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Sep 30 21:44:25 2015 marc brout
** Last update Tue Oct  6 10:23:25 2015 marc brout
*/

void	 my_putchar(char c)
{
  write(1, &c, 1);
}
