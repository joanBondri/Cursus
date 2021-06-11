SRC_CL = 		client_folder/client.c

SRC_SE =		server_folder/server.c

OBJS_CL = $(SRC_CL:.c=.o)

OBJS_SE = $(SRC_SE:.c=.o)

NAME_CL = client

LIB_NAME = ./libft/libft.a

NAME_SE = server

CC = clang

CFLAGS = -Wall -Wextra -Werror -I ./libft/ -I ./include/
RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME_SE) $(NAME_CL)

libft_cmd:
	make -C libft

$(NAME_CL): $(OBJS_CL)
	make -C libft
	$(CC) -o $(NAME_CL) $(OBJS_CL) $(LIB_NAME)

$(NAME_SE): $(OBJS_SE)
	make -C libft
	$(CC) -o $(NAME_SE) $(OBJS_SE) $(LIB_NAME)


clean:
	make clean -C libft
	$(RM) $(OBJS_SE) $(OBJS_CL)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME_SE) $(NAME_CL)

re: fclean all

.PHONY: all clean fclean re
