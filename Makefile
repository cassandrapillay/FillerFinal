# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpillay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/01 15:01:06 by cpillay           #+#    #+#              #
#    Updated: 2018/09/01 15:25:52 by cpillay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

HDR = inc/filler.h\
	  libft/libft.h

SRC = src/check_valid.c src/filler.c src/get_info.c src/main.c 

LIBFT = -L libft/ -lft

OPT = *.o

FLAGS = -Wall -Wextra -Werror -iquoteincludes -iquotelibft -g

$(NAME): all

all:
	make -C libft/ fclean && make -C libft/
	gcc -c $(HDR) $(SRC) $(FLAGS)
	gcc -o $(NAME) $(OPT) $(LIBFT) $(FLAGS)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
