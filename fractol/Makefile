# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 09:54:58 by maximmarhic       #+#    #+#              #
#    Updated: 2025/04/10 09:56:30 by maximmarhic      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= fractol.c draw.c mandelbrot.c julia.c events.c utils.c
OBJ		= $(SRC:.c=.o)

MLX_DIR	= minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

INCLUDES = -I. -I$(MLX_DIR)

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

ifeq ($(wildcard $(LIBFT_LIB)),)
	LIBS =
else
	LIBS = $(LIBFT_LIB)
endif

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	@if [ -d $(LIBFT_DIR) ]; then $(MAKE) -C $(LIBFT_DIR); fi
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(MLX_FLAGS) $(INCLUDES) $(LIBFT_INC) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT_INC) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)
	@if [ -d $(LIBFT_DIR) ]; then $(MAKE) -C $(LIBFT_DIR) clean; fi

fclean: clean
	rm -f $(NAME)
	@if [ -d $(LIBFT_DIR) ]; then $(MAKE) -C $(LIBFT_DIR) fclean; fi

re: fclean all

.PHONY: all clean fclean re
