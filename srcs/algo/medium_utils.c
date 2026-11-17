/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:42:01 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/17 13:32:45 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_b_to_top(t_stack_context *context, int max_index)
{
	if (max_index <= context->b->size - max_index)
	{
		while (max_index > 0)
		{
			do_op(context, op_rb);
			max_index--;
		}
	}
	else
	{
		while (max_index < context->b->size)
		{
			do_op(context, op_rrb);
			max_index++;
		}
	}
}

int	find_index(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	rotate_a(t_stack_context *ctx, int *rb_pending)
{
	if (*rb_pending)
		do_op(ctx, op_rr);
	else
		do_op(ctx, op_ra);
	*rb_pending = 0;
}

void	push_to_b(t_stack_context *ctx, int mid, int *rb_pending)
{
	if (*rb_pending)
		do_op(ctx, op_rb);
	do_op(ctx, op_pb);
	*rb_pending = (ctx->b->size > 1 && ctx->b->array[0] < mid);
}

void	pull_back(t_stack_context *context)
{
	int	max_index;
	int	max_indexl;

	while (context->b->size > 0)
	{
		max_index = find_index(context->b, context->b->size - 1);
		if (context->b->size > 1)
			max_indexl = find_index(context->b, context->b->size - 2);
		if (context->b->size > 1
			&& min(context->b->size - max_indexl, max_indexl)
			< min(context->b->size - max_index, max_index))
		{
			rotate_b_to_top(context, max_indexl);
			do_op(context, op_pa);
			rotate_b_to_top(context, find_index(context->b, context->b->size));
			do_op(context, op_pa);
			do_op(context, op_sa);
		}
		else
		{
			rotate_b_to_top(context, max_index);
			do_op(context, op_pa);
		}
	}
}
