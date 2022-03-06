# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 15:19:49 by aboudoun          #+#    #+#              #
#    Updated: 2021/12/18 16:27:30 by aboudoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_printf.c ft_printf_utils.c 
OFILES = $(CFILES:.c=.o)

CC = gcc
W = -c -Wall -Werror -Wextra
INC = ft_printf.h
NAME = ftprintf.a

all : $(NAME)

$(NAME) : $(OFILES) $(INC)
	@$(CC) $(W) $(CFILES)
	@ar -rc $(NAME) $(OFILES)

clean:
	@rm -f $(OFILES)
fclean : clean
	@rm -f $(NAME)
re : fclean all
