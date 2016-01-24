##
## Makefile for mysh
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Sun Jan 24 02:16:48 2016 marc brout
## Last update Sun Jan 24 19:06:47 2016 marc brout
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

CC      = gcc

CFLAGS  =  -W -Wall -Werror -ansi -pedantic

HDFLAGS = -I./include/

LDFLAGS = -L./lib/ -lmy

RM      = rm -f

.c.o:
	$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
