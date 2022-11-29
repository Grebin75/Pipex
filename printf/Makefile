# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 11:30:17 by hcoutinh          #+#    #+#              #
#    Updated: 2022/03/18 16:17:06 by hcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f

NAME	= libftprintf.a

SRCS	= ft_putnbr.c ft_low.c ft_up.c ft_printf.c \
		  ft_putchar.c ft_putstr.c ft_point.c \
		  ft_unputnbr.c 

OBJS	= $(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all


.PHONY:		all clean fclean re

