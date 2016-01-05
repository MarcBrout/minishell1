##
## Makefile for minishell1
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Tue Dec  1 22:51:35 2015 marc brout
## Last update Tue Jan  5 11:40:35 2016 marc brout
##

SRCP	= ./src/

SRC     = $(SRCP)mysh.c

OBJS    = $(SRC:.c=.o)

NAME    = mysh

CC      = gcc -g

CFLAGS  = -I./include/ -W -Wall -ansi -pedantic

LDFLAGS = -L./lib/ -lmy

RM      = rm -f

.c.o:
	@($(CC) -c $< -o $@  $(CFLAGS))

$(NAME): $(OBJS)
	@($(CC) -o $(NAME) $(OBJS) $(LDFLAGS))

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
