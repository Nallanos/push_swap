/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:30:00 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/10 11:34:17 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_swap(int argc, char **argv)
{
	if (no_error(argc, argv))
	{
		print_split(argv);

		//seul erreur restante a gerer ./push_swap "" pour le moment rentre dans ce if, a gerer dedans imo
		//creer la pile, call les algos, blabla...
	}
	else
		print_error();
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	push_swap(argc, argv);
	free_split(argc, argv);
}
