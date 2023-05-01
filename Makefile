NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

CLEAN = rm -Rf

LIB = ar rcs

SRC = ft_isalnum.c\
	ft_isdigit.c \
	ft_isalpha.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_memset.c\
	ft_strlen.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\

OBJS := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)

clean:
	@$(CLEAN) $(OBJS)

fclean: clean
	@$(CLEAN) $(NAME)

re: fclean all

.PHONY : all clean fclean re

	 ▄▀▀█▄   ▄▀▀▄ █  ▄▀▀▄ █  ▄▀▀▄ ▄▀▀▄ 
	▐ ▄▀ ▀▄ █  █ ▄▀ █  █ ▄▀ █   █    █ 
	  █▄▄▄█ ▐  █▀▄  ▐  █▀▄  ▐  █    █  
	 ▄▀   █   █   █   █   █   █    █   
	█   ▄▀  ▄▀   █  ▄▀   █     ▀▄▄▄▄▀  
	▐   ▐   █    ▐  █    ▐             
	        ▐       ▐                  