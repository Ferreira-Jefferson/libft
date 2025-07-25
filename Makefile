NAME = libft.a
LIB = ./

MANDATORY_SRC = \
	modules/character/ft_isalnum.c \
	modules/character/ft_isalpha.c \
	modules/character/ft_isascii.c \
	modules/character/ft_isdigit.c \
	modules/character/ft_isprint.c \
	modules/character/ft_tolower.c \
	modules/character/ft_toupper.c \
	modules/character/ft_isspace.c \
	modules/character/ft_isupper.c \
	modules/character/ft_islower.c \
	modules/conversion/ft_atoi.c \
	modules/conversion/ft_itoa.c \
	modules/output/ft_putchar_fd.c \
	modules/output/ft_putstr_fd.c \
	modules/output/ft_putendl_fd.c \
	modules/output/ft_putnbr_fd.c \
	modules/output/ft_putchar.c \
	modules/memory/ft_memcmp.c \
	modules/memory/ft_memset.c \
	modules/memory/ft_bzero.c \
	modules/memory/ft_calloc.c \
	modules/memory/ft_memchr.c \
	modules/memory/ft_memcpy.c \
	modules/memory/ft_memmove.c \
	modules/string/ft_strdup.c \
	modules/string/ft_split.c \
	modules/string/ft_strchr.c \
	modules/string/ft_strrchr.c \
	modules/string/ft_strjoin.c \
	modules/string/ft_strtrim.c \
	modules/string/ft_strmapi.c \
	modules/string/ft_substr.c \
	modules/string/ft_strnstr.c \
	modules/string/ft_strncmp.c \
	modules/string/ft_striteri.c \
	modules/string/ft_strlen.c \
	modules/string/ft_strlcpy.c \
	modules/string/ft_strlcat.c

BONUS_SRC = \
	modules/list/ft_lstdelone.c \
	modules/list/ft_lstmap.c \
	modules/list/ft_lstclear.c \
	modules/list/ft_lstiter.c \
	modules/list/ft_lstlast.c \
	modules/list/ft_lstsize.c \
	modules/list/ft_lstadd_back.c \
	modules/list/ft_lstadd_front.c \
	modules/list/ft_lstnew.c

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJS_DIR = objs

CC = gcc
FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)

bonus:
	@$(MAKE) MANDATORY_OBJ="$(MANDATORY_OBJ) $(BONUS_OBJ)"

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(LIB)  $< -o $@
	ar -rcs $(NAME) $< -o $@

clean:
	rm -f $(MANDATORY_OBJ)  $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
