# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/07 16:48:41 by moabdess          #+#    #+#              #
#    Updated: 2026/11/09 16:42:12 by moabdess         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Werror -Wextra -I includes #fsanitize=address

LIBFT = Libft/libft.a

SRCS =	srcs/main.c srcs/errors.c \
		srcs/swap_operations.c srcs/rotate_operations.c srcs/operations.c

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