SRC = main.c \
	  parse.c \
	  algo_func.c \

SRCSDIR = srcs

OBJDIR = $(SRCSDIR)/objects

SRCS = ${SRC:%.c=$(SRCSDIR)/%.c}

OBJS = $(SRCS:%.c=%.o)

NAME = philo

CC = clang

CFLAGS = -Wall -Wextra -Werror -I./includes/

CFLAGS2 = -lpthread

RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS2)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
