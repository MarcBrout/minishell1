##
## Makefile for minishell1
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Tue Dec  1 22:51:35 2015 marc brout
## Last update Tue Jan 12 14:50:42 2016 marc brout
##

SRCP	= ./src/

SRC     = $(SRCP)mysh.c \
	$(SRCP)search_path.c \
	$(SRCP)copy_tabs.c \
	$(SRCP)env.c \
	$(SRCP)pfunc.c \
	$(SRCP)env_suite.c \
	$(SRCP)tools.c \

OBJS    = $(SRC:.c=.o)

NAME    = mysh

CC      = gcc -g

CFLAGS  = -I./include/ -W -Wall -ansi -pedantic -Werror

LDFLAGS = -L./lib/ -lmy

RM      = rm -f

.c.o:
	$(CC) -c $< -o $@  $(CFLAGS)

$(NAME): $(OBJS)
	@($(CC) -o $(NAME) $(OBJS) $(LDFLAGS))

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
