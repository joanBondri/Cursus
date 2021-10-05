SRC1 = 	srcs_checker/checker_bonus.c \
		srcs_checker/operations_bonus.c \
		srcs_checker/parser_bonus.c \
		srcs_checker/print_stack_bonus.c \

SRC2 =	srcs_push_swap/main.c \
		srcs_push_swap/convert.c \
		srcs_push_swap/basic_moves.c \
		srcs_push_swap/parser.c \
		srcs_push_swap/partition.c \
		srcs_push_swap/algo10.c \
		srcs_push_swap/algo2.c \
		srcs_push_swap/algo.c \
		srcs_push_swap/useful_func.c \
		srcs_push_swap/opti.c \
		srcs_push_swap/sort_few_nbr.c \

OBJS1 = $(SRC1:.c=.o)

OBJS2 = $(SRC2:.c=.o)

NAME1 = checker

NAME2 = push_swap

CC = gcc

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror -I ./libft/ -I ./srcs_push_swap/ -I ./srcs_checker/

RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME2)

bonus: $(OBJS1)
	make -C libft
	$(CC)  $(OBJS1) $(LIBFT) -o $(NAME1) $(CFLAGS)

$(NAME2): $(OBJS2)
	make -C libft
	$(CC)  $(OBJS2) $(LIBFT) -o $(NAME2) $(CFLAGS)


clean:
	$(RM) $(OBJS1)
	$(RM) $(OBJS2)
	make -C libft -f Makefile clean

fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)
	$(RM) ./libft.a
	make -C libft -f Makefile fclean

re: fclean all

.PHONY: all clean fclean re
