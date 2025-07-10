NAME = libft.a

SRC = ft_isalpha.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \

OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re clean
	@$(CC) $(FLAGS) test.c -L. -lft -o test
	./test
	@rm -f test
	@make clean