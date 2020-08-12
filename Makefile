# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlavona <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:29:52 by jlavona           #+#    #+#              #
#    Updated: 2019/09/26 19:54:57 by jlavona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# C compiler
CC = gcc

# Compiler flags
#
# -ggdb3 for Valgrind
CFLAGS = -Wextra -Werror -ggdb3

# Source files
SRCS = main.c read_file.c draw.c transform.c hooks.c

# C preprocessor flags (where to look for includes)
CPPFLAGS = -Iincludes

# Libs
#
# Linux: -L ./libft -lft -L ./minilibx -lmlx -lX11 -lXext -lm
LIBS = -L ./libft -lft \
	   -L ./minilibx -lmlx \
	   -lX11 -lXext -lm

# Object files
OBJS = $(SRCS:.c=.o)

# Output name
NAME = fdf

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) -o $(NAME) $(CPPFLAGS) $(LIBS)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(CPPFLAGS)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean:
	make -C libft fclean
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
