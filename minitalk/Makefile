# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 17:00:00 by mmarhic           #+#    #+#              #
#    Updated: 2025/04/03 08:37:40 by maximmarhic      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
LIBFT   = libft/libft.a
INCLUDE = -Ilibft

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): server.c $(LIBFT)
	$(CC) $(CFLAGS) server.c $(LIBFT) $(INCLUDE) -o $(NAME_SERVER)

$(NAME_CLIENT): client.c $(LIBFT)
	$(CC) $(CFLAGS) client.c $(LIBFT) $(INCLUDE) -o $(NAME_CLIENT)

$(LIBFT):
	make -C libft

clean:
	make clean -C libft

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C libft

re: fclean all