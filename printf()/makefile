# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 17:36:03 by kmurched          #+#    #+#              #
#    Updated: 2026/01/16 18:32:38 by kmurched         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs
RM			= rm -f

# List ALL your source files here (add every .c you have)
SRCS		= ft_printf.c \
			  ft_putnbr_printf.c \
			  digits_counter.c \
			  test.c \
			  # add others: e.g. handle_char.c handle_string.c handle_hex.c etc.

OBJS		= $(SRCS:.c=.o)

# Optional: if you have a header
HEADERS		= 	ft_printf.h\
				libft\libft.h\

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

%.o:		%.c $(HEADERS)
			$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

# Convenience rule for quick testing
test:		re
			$(CC) $(CFLAGS) test.c -L. -lftprintf -o test.out
			./test.out

.PHONY:		all clean fclean re test