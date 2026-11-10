# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/07 16:48:41 by moabdess          #+#    #+#              #
#    Updated: 2026/11/10 11:28:10 by abenameu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Werror -Wextra -I includes #fsanitize=address

LIBFT = Libft/libft.a

SRCS = srcs/push_swap.c srcs/setup.c srcs/utils.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C Libft/

%.o: %.c
	cc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)
	make -C Libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C Libft/ fclean

re: fclean all

.PHONY: all clean fclean re