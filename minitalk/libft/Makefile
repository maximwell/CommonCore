# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 17:21:41 by mmarhic           #+#    #+#              #
#    Updated: 2024/10/23 18:26:03 by mmarhic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =		ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_printf.c \
            ft_putchar_sp.c \
            ft_putnbr_sp.c \
            ft_putnbr_unsigned_sp.c \
            ft_putptr_sp.c \
            ft_putstr_sp.c \
            ft_puthexa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c 

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
RM_WIN = del /S /Q
AR = ar crs

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(CUSTOM_OBJS)

clean-win:
	$(RM_WIN) "*.o"

fclean:	clean
	$(RM) $(NAME)

fclean-win:	clean-win
	$(RM_WIN) "$(NAME)"

re:	fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

custom: $(OBJS) $(BONUS_OBJS) $(CUSTOM_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS) $(CUSTOM_OBJS)

.PHONY:	all clean clean-win fclean fclean-win re bonus custom
