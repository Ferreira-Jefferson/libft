NAME = libft.a

SRC_DIRS = allocation fd list memory number string

MANDATORY_SRC = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
    ar rcs $@ $^

%.o: %.c
    $(CC) $(CFLAGS) -I. -c $< -o $@

clean:
    rm -f $(MANDATORY_OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus