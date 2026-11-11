# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/07 16:48:41 by moabdess          #+#    #+#              #
#    Updated: 2026/11/11 15:34:38 by abenameu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Werror -Wextra -I includes #fsanitize=address

LIBFT = Libft/libft.a

SRCS =	srcs/main.c \
		srcs/parsing.c \
		srcs/errors.c \
		srcs/utils.c \
		srcs/setup.c \
		srcs/setup_utils.c \
		srcs/op/operations.c \
		srcs/op/swap_operations.c \
		srcs/op/rotate_operations.c \
		srcs/argument_parsing.c \
		srcs/disorder.c \
		srcs/op/push_operations.c \
		srcs/op/rotate_op_reversed.c \
		srcs/algo/simple.c \
		srcs/algo/medium.c \
		srcs/algo/complex.c \
		srcs/algo/adaptive.c \
		srcs/algo/math.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C Libft/

%.o: %.c includes/push_swap.h
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