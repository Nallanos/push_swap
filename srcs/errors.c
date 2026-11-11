/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:02:46 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/11 16:04:01 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error()
{
	write(2, "Error\n", 6);
	return (0);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		++i;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		++i;
	}
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (0);
	return (1);
}

int has_duplicates(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (ft_atol(input[i]) == ft_atol(input[j]))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	no_error(char **input)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (!is_valid_number(input[i]))
			return (0);
		++i;
	}
	if (has_duplicates(input))
		return (0);
	return (1);
}

int exit_on_error(char **input, t_stack_context *context)
{
	print_error();
	if (context)
		free_t_stack_context(context);
	if (input)
		free_split(2, input);
	return (0);
}