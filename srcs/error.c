/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:02:46 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/10 11:03:23 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error()
{
	write(2, "Error\n", 6);
}

int	no_error(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = -1;
	if (argc == 2)
		argc = ft_tablen(argv);
	else if (argc > 2)
		i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
		j = 0;
		if (ft_atoi(argv[i]) < 0)
			++j;
		if (!argv[i][j] || ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648) //line too long
			return (0);
		--j;
		while (argv[i][++j])
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
	}
	return (1);
}

