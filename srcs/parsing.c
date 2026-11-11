/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:06:25 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/11 09:47:32 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_mode	parse_mode(char *str)
{
	if (ft_strncmp(str, "--simple", 9) == 0)
		return (simple);
	if (ft_strncmp(str, "--medium", 9) == 0)
		return (medium);
	if (ft_strncmp(str, "--complex", 10) == 0)
		return (complex);
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (adaptive);
	return (error);
}

int	is_bench(int argc, char **argv)
{
	int	i;

	i = 0;
	while(i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			return (1);
		i++;
	}
	return (0);
}

t_mode	get_mode(int argc, char **argv)
{
	int		i;
	t_mode	mode;

	i = 0;
	mode = undefined;
	while(i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-' 
			&& ft_strncmp(argv[i], "--bench", 8))
		{
			if (mode != undefined)
				return (error);
			mode = parse_mode(argv[i]);
		}
		i++;
	}
	if (mode == undefined)
		return (adaptive);
	return (mode);
}
t_exec_context	get_exec_context(int argc, char **argv)
{
	t_exec_context	context;

	context.mode = get_mode(argc, argv);
	context.is_bench = is_bench(argc, argv);
	return (context);
}
