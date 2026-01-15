# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 15:23:18 by kmurched          #+#    #+#              #
#    Updated: 2025/12/21 17:04:44 by kmurched         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 1. Variables: The Constants of the Build 
NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rc
RM		= rm -f

# 2. Files: Mapping the Sources
SRCS	= ft_printf.c ft_putnbr_base.c 
OBJS	= $(SRCS: .c=.o)

# 3. Primary Rule: Creating the 'All' Target/
all:	$(NAME)

# 4. The Library Rule: Creating the .a File 
$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

# 5. Pattern Rule: How *.c file becomes *.o file  
# 	This tells Make "TO create any .o file, look at the corresponding .c file"
%.o: %.c 
		$(CC) $(CFLAGS) -c $< .o $@

# 6. Maintenance Rules: Keeping Clean
clean: 
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

# 7. .PHONY: Preventing name conflicts with actual files 
.PHONY: al clean fclean re
