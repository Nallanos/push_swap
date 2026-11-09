/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:30:00 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/09 16:44:16 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	// t_stack	a;
	// t_stack	b;
	// t_enum	operations;
	// t_context context;
	
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (no_error(argc, argv) && argv[0])
	{
		printf("OK\n"); //test
		//creer la pile, call les algos, blabla...
	}
	else
		printf("Error\n"); //a remplacer avec ft_printf
	free_split(argc, argv);
}

