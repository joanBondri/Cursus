SRC = 		srcs/algo_math.c \
			srcs/main.c \
			srcs/mlx_setup.c \
			srcs/graphique.c \
			srcs/parse.c \
			srcs/error.c \
			srcs/event.c \
			srcs/hsv.c \

OBJS = $(SRC:.c=.o)

NAME = fractol

CC = clang

CFLAGS = -Wall -Wextra -Werror -I./ -I ./libft/ -I./minilibx/
CFLAGS2 = -I./minilibx -I/usr/include -I ./ -lXext -lX11 -lbsd -L./minilibx -lm -lmlx ./libft/libft.a
RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C minilibx
	make -C libft
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS2)

all: $(NAME)

clean:
	$(RM) libft.a
	$(RM) $(OBJS)
	make -C minilibx -f Makefile clean
	make -C libft -f Makefile clean

fclean: clean
	$(RM) $(NAME)
	make -C libft -f Makefile fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
