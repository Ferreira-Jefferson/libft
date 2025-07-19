NAME = libft.a
LIB = ./

MANDATORY_SRC 	= 	ft_isalnum.c	ft_isalpha.c	ft_isascii.c	ft_isdigit.c \
					ft_isprint.c	ft_tolower.c	ft_toupper.c	ft_atoi.c \
					ft_memcmp.c		ft_strncmp.c	ft_itoa.c		ft_strdup.c \
					ft_split.c		ft_strchr.c		ft_strrchr.c	ft_strjoin.c \
					ft_strtrim.c	ft_strmapi.c	ft_substr.c		ft_strnstr.c \
					ft_bzero.c		ft_putnbr_fd.c	ft_putchar_fd.c	ft_putstr_fd.c \
					ft_putendl_fd.c	ft_memset.c		ft_calloc.c		ft_memchr.c \
					ft_memcpy.c		ft_memmove.c	ft_striteri.c	ft_strlen.c \
					ft_strlcpy.c	ft_strlcat.c
			
BONUS_SRC 		= 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
					ft_lstmap.c

EXTRA_SRC 		= 	ft_isspace.c ft_isupper.c ft_islower.c ft_strstr.c ft_putchar.c \

MANDATORY_OBJ 	= $(MANDATORY_SRC:.c=.o)
BONUS_OBJ 		= $(BONUS_SRC:.c=.o)
EXTRA_OBJ 		= $(EXTRA_SRC:.c=.o)

OBJS_DIR = objs

CC = gcc
AR_COMMAND = ar rcs
FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(MANDATORY_OBJ) $(BONUS_OBJ) $(EXTRA_OBJ)
	$(AR_COMMAND) $(NAME) $(MANDATORY_OBJ) $(BONUS_OBJ) $(EXTRA_OBJ)
	mkdir -p $(OBJS_DIR)
	mv *.o $(OBJS_DIR)

bonus: $(BONUS_OBJ)

extra: $(EXTRA_OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(LIB)  $< -o $@ 
	ar -rcs $(NAME) $< -o $@

clean:
	rm -f $(MANDATORY_OBJ)  $(BONUS_OBJ) $(EXTRA_OBJ)

fclean: clean
	rm -f $(NAME)
	rmdir $(OBJS_DIR) 2>/dev/null || true

re: fclean all

test: re
	@$(CC) $(FLAGS) -g test.c -L. -lbsd -lft -o test
	./test
	## @rm -f test
	@make fclean