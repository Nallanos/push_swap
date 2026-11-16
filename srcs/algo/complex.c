/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:58:21 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/16 14:46:12 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	quicksort_a(t_stack_context *context, int size)
{
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (context->a->array[0] > context->a->array[1])
			do_op(context, op_sa);
		return ;
	}
	if (size == 3)
	{
		sort_three_a(context);
		return ;
	}
	partition_a(context, size);
	quicksort_a(context, size - (size / 2));
	quicksort_b(context, ((size / 2) - (size / 4)));
	quicksort_b(context, size / 4);
}

void	quicksort_b(t_stack_context *context, int size)
{
	if (size <= 0)
		return ;
	else if (size == 1)
		do_op(context, op_pa);
	else if (size == 2)
		push_two_b(context);
	else if (size == 3)
		sort_three_b(context);
	else
	{
		partition_b(context, size);
		quicksort_a(context, size - (size / 2));
		quicksort_b(context, size / 2);
	}
}

void	complex_sort(t_stack_context *context, float disorder)
{
	(void) disorder;
	if (!index_stack(context->a))
		return ;
	quicksort_a(context, context->a->size);
}
