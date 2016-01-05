/*
** get_next_line.h for gnl
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Jan  4 10:37:28 2016 marc brout
** Last update Mon Jan  4 15:08:39 2016 marc brout
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# include <stdlib.h>
# include <unistd.h>
# ifndef READ_SIZE
#  define READ_SIZE (1000)
# endif /* !READ_SIZE_H_ */

char *my_realloc(char *, int);
char *get_next_line(const int fd);
char *get_last_buff(char *, char *, int *, int *);

#endif /* !GET_NEXT_LINE_H_ */
