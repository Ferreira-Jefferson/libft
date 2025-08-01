NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libft.a
OBJ_DIR = objs

MANDATORY_SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				ft_isprint.c ft_tolower.c ft_toupper.c ft_atoi.c \
				ft_memcmp.c ft_strncmp.c ft_itoa.c ft_strdup.c \
				ft_split.c ft_strchr.c ft_strrchr.c ft_strjoin.c \
				ft_strtrim.c ft_strmapi.c ft_substr.c ft_strnstr.c \
				ft_bzero.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_memset.c ft_calloc.c ft_memchr.c \
				ft_memcpy.c ft_memmove.c ft_striteri.c ft_strlen.c \
				ft_strlcpy.c ft_strlcat.c

BONUS_SRC = ft_lstdelone_bonus.c ft_lstmap_bonus.c ft_lstclear_bonus.c \
			ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c \
			ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstnew_bonus.c 

EXTRA_SRC = ft_atoi_base.c ft_convert_base.c ft_is_valid_base.c ft_itoa_base.c \
			ft_putunbr_fd.c ft_realloc.c ft_to_free.c ft_count_decimal_places.c \
			ft_isspace.c

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
BONUS_OBJ     = $(BONUS_SRC:.c=.o)
EXTRA_OBJ     = $(EXTRA_SRC:.c=.o)

MANDATORY_OBJ = $(addprefix $(OBJ_DIR)/, $(MANDATORY_SRC:.c=.o))
BONUS_OBJ     = $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))
EXTRA_OBJ     = $(addprefix $(OBJ_DIR)/, $(EXTRA_SRC:.c=.o))


OBJS = $(MANDATORY_OBJ) $(EXTRA_OBJ)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^
 
bonus: $(NAME)
	@$(MAKE) OBJS="$(OBJ) $(BONUS_OBJ)"

extra: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJ) $(BONUS_OBJ) $(EXTRA_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus extra
