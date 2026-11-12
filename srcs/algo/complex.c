/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:58:21 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/12 13:05:01 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		++bits;
	return (bits);
}

static void	radix(t_stack_context *context, int bit)
{}

void	complex_sort(t_stack_context *context, float disorder)
{
	int	bit;
	int	max_bits;
	(void)disorder;

	if (!index_stack(context->a))
		return ;
	max_bits = get_max_bits(context->a->size);
	bit = -1;
	while (++bit < max_bits)
		radix(context, bit);
}
