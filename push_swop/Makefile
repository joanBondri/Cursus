SRC2 =	srcs/main.c \
		srcs/convert.c \
		srcs/basic_moves.c \
		srcs/parser.c \
		srcs/partition.c \
		srcs/algo.c \
		srcs/sort_few_nbr.c \

#OBJS1 = $(SRC1:.c=.o)

OBJS2 = $(SRC2:.c=.o)

NAME1 = checker

NAME2 = push_swap

CC = clang

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror -I ./libft/ -I ./srcs/

RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME2)

#$(NAME1): $(OBJS1)
#		make -C libft
#		$(CC)  $(OBJS1) $(LIBFT) -o $(NAME1) $(CFLAGS)

$(NAME2): $(OBJS2)
		make -C libft
		$(CC)  $(OBJS2) $(LIBFT) -o $(NAME2) $(CFLAGS)


clean:
	$(RM) $(OBJS2)
	make -C libft -f Makefile clean

fclean: clean
	$(RM) $(NAME2)
	$(RM) ./libft.a
	make -C libft -f Makefile fclean

re: fclean all

.PHONY: all clean fclean re
