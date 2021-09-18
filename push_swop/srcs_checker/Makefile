SRC1 = 	checker_folder/checker.c \
		Utils/operations.c \
		Utils/parser.c \
		Utils/print_stack.c \

OBJS1 = $(SRC1:.c=.o)

NAME1 = checker

CC = clang

CFLAGS = -Wall -Wextra -Werror -I printf/Includes/ -I checker_folder/ -I Utils -I ./
RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME1): libr $(OBJS1)
	 $(CC)  $(OBJS1) -o $(NAME1)  -L./printf -lftprintf $(CFLAGS)

libr:
		make -C printf

all: $(NAME1) $(NAME2)


clean:
	$(RM) $(OBJS1)

fclean: clean
	$(RM) $(NAME1)

re: fclean all

.PHONY: all clean fclean re
