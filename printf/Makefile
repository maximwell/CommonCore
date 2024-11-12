# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 17:21:41 by mmarhic           #+#    #+#              #
#    Updated: 2024/11/12 22:16:03 by mmarhic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =		ft_printf.c \
            ft_putchar_sp.c \
            ft_putnbr_sp.c \
            ft_putnbr_unsigned_sp.c \
            ft_putptr_sp.c \
            ft_putstr_sp.c \
            ft_puthexa.c

TEST_SRC = main.c
TEST_OBJS = $(TEST_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(TEST_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean clean-win fclean fclean-win re bonus custom
