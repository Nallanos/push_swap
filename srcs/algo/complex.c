/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:58:21 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/12 17:33:45 by moabdess         ###   ########.fr       */
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
{
	int	i;
	int	size;

	i = 0;
	size = context->a->size;
	while (i < size)
	{
		if (((context->a->array[0] >> bit) & 1) == 1)
			do_op(context, op_ra);
		else
			do_op(context, op_pb);
		++i;
	}
	while (context->b->size > 0) //ici ca push tout vers a apres chaque modif
		do_op(context, op_pa); //ca marche mais pas opti il faut juste faire le push vers la fin
}

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
