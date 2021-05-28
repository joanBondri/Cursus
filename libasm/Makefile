OBJS = $(SRC:.s=.o)

SRC =		ft_strcmp.s \
		ft_read.s \
		ft_strcpy.s \
		ft_strdup.s \
			ft_strlen.s \
			ft_write.s \

NAME = libasm.a

RM = rm -rf

%.o : %.s
	nasm -f elf64 $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

try : $(NAME)
	clang main.c -L./ -lasm -o try
	./try

.PHONY: all clean fclean re
