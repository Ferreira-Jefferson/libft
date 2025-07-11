NAME = libft.a

SRC = ft_isalpha.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \

LIB = ./libft.h

OBJ = $(SRC:.c=.o)

CC = cc
AR_COMMAND = ar rcs
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(AR_COMMAND) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -I $(LIB) -c $< -o $@

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