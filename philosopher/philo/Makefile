SRC = 		main.c\
			parse.c\

OBJS = $(SRC:.c=.o)

NAME = philo

CC = clang

CFLAGS = -Wall -Wextra -Werror -I./
RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) 

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
