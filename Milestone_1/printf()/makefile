# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 15:23:18 by kmurched          #+#    #+#              #
#    Updated: 2025/12/17 17:47:28 by kmurched         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a
# Compiler and Flags 
CC		= 	CC
CFLAGS	= 	-Wall -Wextra -Werror 
# Source & Object files to be Compiled 
SRCS 	= 	ft_printf.c\
			fun_test.c

OBJS	=	$(SRCS: .c=.o)
#Defualt Target 

.PHONY: all clean fclean re

all: $(NAME)

# Link Steps: BUild the final executable 
$(NAME): $(OBJS)
		@make -C libft
		@cp libft/libft.a $(libft)
		@mv libft.a $(libft)
		ar rcs $(libft) $(OBJS)

#Compile Steps
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

#House keeping. 
clean: rm -f $(OBJ)
		@make clean -c

fclean: clean 
		rm $(NAME)

re:		fclean all