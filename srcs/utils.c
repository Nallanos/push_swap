/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:56:02 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/10 15:47:52 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		++i;
	}
}
int	ft_tablen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
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
int ft_strcat(char *dest, const char *src)
{
	int	i;
	int	dest_len;

	dest_len = 0;
	while (dest[dest_len])
		dest_len++;
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + i);
}

