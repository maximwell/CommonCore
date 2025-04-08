# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 00:38:59 by maximmarhic       #+#    #+#              #
#    Updated: 2025/04/08 18:04:46 by maximmarhic      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= .
INS_DIR		= instructions
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC_FILES = main.c parser.c parser_utils.c exit_error.c sort_three.c sort_five.c sort.c indexing.c \
			$(INS_DIR)/swap.c $(INS_DIR)/push.c $(INS_DIR)/rotate.c $(INS_DIR)/reverse.c


SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(SRC:.c=.o)

HEADER		= push_swap.h

RM			= rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
