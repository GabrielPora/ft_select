#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 16:02:07 by pxia              #+#    #+#              #
#    Updated: 2015/06/08 21:25:49 by pxia             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_select
LIBFT_LIB = ./libft/libft.a
SRC_DIR	= ./src/
SRC	= dir_key.c info.c list.c main.c mode.c prin.c search.c select.c tools.c \
	signal.c window.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ	= $(SRCS:.c=.o)
INC	= -I ./libft -I ./includes
FLAGS = -Wall -Werror -Wextra -O3

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) -lncurses

$(LIBFT_LIB):
	make -C libft/

%.o: %.c
	gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
