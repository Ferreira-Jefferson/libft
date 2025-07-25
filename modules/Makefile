NAME = libft.a

SRC_DIRS = allocation fd list memory number string

LIBFT_SRC = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(LIBFT_OBJ)
	ar rcs $(NAME) $(LIBFT_OBJ)
	rm -f $(LIBFT_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re