# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:29:52 by jlavona           #+#    #+#              #
#    Updated: 2020/08/14 06:03:42 by jlavona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# C compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = ft_strlen.c ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_putchar.c ft_memset.c \
	   ft_memcpy.c ft_memcmp.c ft_putchar_fd.c ft_striter.c ft_strmap.c \
	   ft_isspace.c ft_atoi.c ft_bzero.c ft_memchr.c ft_memccpy.c \
	   ft_striteri.c ft_strcmp.c ft_strmapi.c ft_strncmp.c ft_strdup.c \
	   ft_strcpy.c ft_strcat.c ft_strnlen.c ft_strncat.c ft_strlcat.c \
	   ft_strchr.c ft_strrchr.c ft_putstr.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putendl.c ft_strclr.c ft_putnbr_fd.c ft_putnbr.c ft_memalloc.c \
	   ft_memdel.c ft_strdel.c ft_strequ.c ft_strnequ.c ft_strncpy.c \
	   ft_memmove.c ft_strstr.c ft_strnew.c ft_strsub.c ft_strjoin.c \
	   ft_strnstr.c ft_itoa.c ft_delptoparr.c ft_strtrim.c ft_strsplit.c \
	   ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	   ft_lstmap.c get_next_line.c ft_wordcount.c ft_atoi_base.c

# C preprocessor flags: where to look for includes
CPPFLAGS = -Iincludes

# Object files
OBJS = $(SRCS:.c=.o)

# Output name
NAME = libft.a

all: $(NAME)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(CPPFLAGS)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
