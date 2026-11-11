/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:22:11 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/11 09:46:30 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	get_disorder(int *input, int len)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	total_pairs = 0;
	i = 0;
	mistakes = 0;
	if (len <= 1)
		return (0.0);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			total_pairs++;
			if (input[i] > input[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((float)mistakes / total_pairs);
}
