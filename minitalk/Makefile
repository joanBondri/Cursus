SRC_CL = 		client_folder/client.c

SRC_SE =		server_folder/server.c

OBJS_CL = $(SRC_CL:.c=.o)

OBJS_SE = $(SRC_SE:.c=.o)

NAME_CL = client

NAME_SE = server

CC = clang

CFLAGS = -Wall -Wextra -Werror -I ./include/ -I ./libft/ -L./libft/ -lft
RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME_SE) $(NAME_CL) libft_cmd

$(NAME_CL): $(OBJS_CL) libft_cmd
	$(CC) -o $(NAME_CL) $(OBJS_CL)

$(NAME_SE): $(OBJS_SE) libft_cmd
	$(CC) -o $(NAME_SE) $(OBJS_SE)
libft_cmd:
	make -C libft


clean:
	make clean -C libft
	$(RM) $(OBJS_SE) $(OBJS_CL)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME_SE) $(NAME_CL)

re: fclean all

.PHONY: all clean fclean re
