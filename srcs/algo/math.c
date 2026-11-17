/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:33:04 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/17 13:31:50 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i <= nb && i <= 46340)
	{
		i++;
	}
	return (i - 1);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
