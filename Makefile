# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppipes <ppipes@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 16:22:35 by ppipes            #+#    #+#              #
#    Updated: 2020/07/21 10:40:15 by ppipes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_itoa.c ft_atoi.c ft_printf_utils.c \
ft_printf_parser.c ft_printf_type_digit.c ft_printf_type_other.c \
ft_printf_int_flags.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

%.o: %.c ft_printf.h
	gcc $(CFLAGS) -c $<
all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	rm -f $(OBJ) 
fclean: clean
	rm -f $(NAME)
re: fclean all
