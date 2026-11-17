/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:57:53 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/17 13:08:24 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_max_index(t_stack *s)
{
	int	i;
	int	index;
	int	value;

	i = 0;
	value = s->array[0];
	index = 0;
	while (i < s->size)
	{
		if (s->array[i] > value)
		{
			value = s->array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	index_stack(t_stack *stack)
{
	int	i;
	int	j;
	int	*ranks;

	ranks = (int *)malloc(sizeof(int) * stack->size);
	if (!ranks)
		return (0);
	i = 0;
	while (i < stack->size)
	{
		ranks[i] = 0;
		j = 0;
		while (j < stack->size)
		{
			if (stack->array[j] < stack->array[i])
				ranks[i]++;
			j++;
		}
		i++;
	}
	ft_memcpy(stack->array, ranks, sizeof(int) * stack->size);
	free(ranks);
	return (1);
}

void	push_chunks(t_stack_context *ctx, int chunk_size)
{
	int	top;
	int	pushed;
	int	rb_pending;

	top = chunk_size;
	pushed = 0;
	rb_pending = 0;
	while (ctx->a->size > 0)
	{
		if (pushed == top)
			top += chunk_size;
		if (ctx->a->array[0] < top)
		{
			push_to_b(ctx, top - chunk_size / 2, &rb_pending);
			pushed++;
		}
		else
			rotate_a(ctx, &rb_pending);
	}
	if (rb_pending)
		do_op(ctx, op_rb);
}

void	medium_sort(t_stack_context *context)
{
	int	chunk_size;
	int	chunk_count;

	chunk_count = ft_sqrt(context->a->size) / 2;
	if (chunk_count < 1)
		chunk_count = 1;
	chunk_size = context->a->size / chunk_count;
	if (chunk_size < 1)
		chunk_size = 1;
	if (!index_stack(context->a))
		return ;
	push_chunks(context, chunk_size);
	pull_back(context);
}
