SRC = 		algo_math.c \
			main.c \
			mlx_setup.c \
			graphique.c \
			parse.c \

OBJS = $(SRC:.c=.o)

NAME = fractol

CC = clang

CFLAGS = -Wall -Wextra -Werror -I./
CFLAGS2 = -I./minilibx-linux -I/usr/include -I ./ -L./ -lftprintf -lXext -lX11 -lbsd -L./minilibx-linux -lm -lmlx
RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C minilibx-linux
	make -C printf
	mv printf/libftprintf.a ./libftprintf.a
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS2)

all: $(NAME)

clean:
	$(RM) libftprintf.a
	$(RM) $(OBJS)
	make -C minilibx-linux -f Makefile clean
	make -C printf -f Makefile clean

fclean: clean
	$(RM) $(NAME)
	make -C printf -f Makefile fclean

re: fclean all

.PHONY: all clean fclean re
