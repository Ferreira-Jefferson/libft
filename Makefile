NAME = libft.a

SRC = $(wildcard *.c)
LIB = ./libft.h

OBJ = $(SRC:.c=.o)
OBJS_DIR = objs

CC = cc
AR_COMMAND = ar rcs
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(AR_COMMAND) $(NAME) $(OBJ)
	mkdir -p $(OBJS_DIR)
	mv *.o $(OBJS_DIR)

%.o: %.c
	$(CC) $(FLAGS) -I $(LIB) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rmdir $(OBJS_DIR) 2>/dev/null || true

re: fclean all

test: re
	@$(CC) $(FLAGS) test.c -L. -lft -o test
	./test
	@rm -f test
	@make fclean