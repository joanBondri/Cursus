SRC = 		Utiles/per_type/type_uint.c \
			Utiles/per_type/type_str.c \
			Utiles/per_type/type_pointer.c \
			Utiles/per_type/type_percent.c \
			Utiles/per_type/type_int.c \
			Utiles/per_type/type_hexa.c \
			Utiles/per_type/type_char.c \
			Utiles/set_struct.c \
			Utiles/put_chars.c \
			Utiles/put_nbrs.c \
			Utiles/put_others.c \
			Utiles/parse.c \
			Utiles/print.c \
			ft_printf.c \

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

CC = gcc

CFLAGS = -I Includes -Wall -Wextra -Werror

RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
		make -C libft
		mv libft/libft.a $(NAME)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make -C libft -f Makefile clean

fclean: clean
	$(RM) $(NAME)
	make -C libft -f Makefile fclean

re: fclean all

.PHONY: all clean fclean re
