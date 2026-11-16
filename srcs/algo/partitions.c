/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:37:36 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/16 14:59:42 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	send_next(t_stack_context *context, t_split *s)
{
	if (s->is_next)
	{
		do_op(context, op_rb);
		++s->rotate_b;
		s->is_next = 0;
	}
}

void	restore_split(t_stack_context *context, t_split *s)
{
	send_next(context, s);
	while (s->had_elements && !(s->full) && s->rotate_a > 0 && s->rotate_b > 0)
	{
		do_op(context, op_rrr);
		--s->rotate_a;
		--s->rotate_b;
	}
	while (s->had_elements && s->rotate_b > 0)
	{
		do_op(context, op_rrb);
		--s->rotate_b;
	}
	while (!(s->full) && s->rotate_a > 0)
	{
		do_op(context, op_rra);
		--s->rotate_a;
	}
}

int	get_pivot(int *array, int n, int k)
{
	int	i;
	int	j;
	int	smaller;

	i = 0;
	while (i < n)
	{
		smaller = 0;
		j = 0;
		while (j < n)
		{
			if (array[j] < array[i])
				++smaller;
			++j;
		}
		if (smaller == k)
			return (array[i]);
		++i;
	}
	return (array[0]);
}

void	partition_a(t_stack_context *context, int size)
{
	t_split	s;
	int		pushed;

	ft_bzero(&s, sizeof(t_split));
	s.p1 = get_pivot(context->a->array, size, size / 4);
	s.p2 = get_pivot(context->a->array, size, size / 2);
	s.had_elements = 0;
	if (context->b->size > 0)
		s.had_elements = 1;
	s.full = 0;
	if (context->a->size == size)
		s.full = 1;
	pushed = 0;
	while (pushed < size / 2)
	{
		if (context->a->array[0] >= s.p2)
			keep_in_a(context, &s);
		else
		{
			send_to_b(context, &s);
			++pushed;
		}
	}
	restore_split(context, &s);
}

void	partition_b(t_stack_context *context, int size)
{
	int	pivot;
	int	pushed;
	int	rotated;

	pivot = get_pivot(context->b->array, size, size / 2);
	pushed = 0;
	rotated = 0;
	while (pushed < size - size / 2)
	{
		if (context->b->array[0] >= pivot)
		{
			do_op(context, op_pa);
			++pushed;
		}
		else
		{
			do_op(context, op_rb);
			++rotated;
		}
	}
	while (context->b->size > (size / 2) && rotated > 0)
	{
		do_op(context, op_rrb);
		--rotated;
	}
}
