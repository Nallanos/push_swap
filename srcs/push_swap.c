/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:30:00 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/09 13:00:27 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_tablen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
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

void	free_split(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc == 2)
	{
		while (argv[++i])
			free(argv[i]);
		free(argv);
	}
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (no_error(argc, argv))
	{
		printf("OK\n"); //test
		//seul erreur restante a gerer ./push_swap "" pour le moment rentre dans ce if, a gerer dedans imo
		//creer la pile, call les algos, blabla...
	}
	else
		printf("Error\n"); //a remplacer avec ft_printf
	free_split(argc, argv);
}

