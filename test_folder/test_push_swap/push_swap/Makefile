SRC2 =	push_swap_folder/push_swap.c \
		Utils/operations.c \
		Utils/parser.c \
		push_swap_folder/quicksort.c \
		Utils/print_stack.c \

SRC1 = 	checker_folder/checker.c \
		Utils/operations.c \
		Utils/parser.c \
		push_swap_folder/quicksort.c \
		Utils/print_stack.c \

OBJS1 = $(SRC1:.c=.o)

OBJS2 = $(SRC2:.c=.o)

NAME1 = checker

NAME2 = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror -I printf/Includes/ -I checker_folder/ -I Utils -I ./
RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME1): libr $(OBJS1)
	 $(CC)  $(OBJS1) -o $(NAME1)  -L./printf -lftprintf $(CFLAGS)

$(NAME2): libr $(OBJS2)
	 $(CC)  $(OBJS2) -o $(NAME2)  -L./printf -lftprintf $(CFLAGS)

libr:
		make -C printf

all: $(NAME1) $(NAME2)


clean:
	$(RM) $(OBJS1)
	$(RM) $(OBJS2)
	make -C printf -f Makefile clean

fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)
	$(RM) ./libftprintf.a
	make -C printf -f Makefile fclean

re: fclean all

.PHONY: all clean fclean re
