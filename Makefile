# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/09 12:29:52 by jlavona           #+#    #+#              #
#    Updated: 2020/08/21 14:41:04 by jlavona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# C compiler
CC = gcc

# Compiler flags
#
# -ggdb3 for Valgrind
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = main.c read_file.c draw.c hooks.c bresenham.c \
	   colorize.c lists_and_validation.c

# C preprocessor flags (where to look for includes)
CPPFLAGS = -Iincludes

# Libs
#
# Linux:
#LIBS = -L ./libft -lft -L ./minilibx -lmlx -lX11 -lXext -lm
# Mac:
LIBS = -L ./libft -lft -L ./minilibx_macos -lmlx -framework OpenGL \
	-framework AppKit

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
