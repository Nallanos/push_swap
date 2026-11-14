/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:35:18 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/14 14:20:45 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	temp = a->array[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[i] = temp;
}

void	rb(t_stack *b)
{
	ra(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
