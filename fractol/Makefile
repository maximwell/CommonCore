# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 09:54:58 by maximmarhic       #+#    #+#              #
#    Updated: 2025/04/23 16:29:06 by mmarhic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= fractol.c draw.c mandelbrot.c julia.c events.c utils.c
OBJ		= $(SRC:.c=.o)

MLX_DIR	= minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES = -I. -I$(MLX_DIR)

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLX_FLAGS) $(INCLUDES) $(LIBFT_INC) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT_INC) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
