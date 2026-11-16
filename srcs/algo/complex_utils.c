/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:37:25 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/16 15:01:57 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three_a(t_stack_context *context)
{
	int	*a;

	a = context->a->array;
	if (a[0] > a[1])
		do_op(context, op_sa);
	if (a[1] > a[2])
	{
		do_op(context, op_pb);
		do_op(context, op_sa);
		do_op(context, op_pa);
		if (a[0] > a[1])
			do_op(context, op_sa);
	}
}

void	push_two_b(t_stack_context *context)
{
	if (context->b->array[0] < context->b->array[1])
		do_op(context, op_sb);
	do_op(context, op_pa);
	do_op(context, op_pa);
}

void	sort_three_b(t_stack_context *context)
{
	int	*b;

	b = context->b->array;
	if (b[1] > b[0] && b[1] > b[2])
		do_op(context, op_sb);
	if (b[0] > b[1] && b[0] > b[2])
	{
		do_op(context, op_pa);
		push_two_b(context);
		return ;
	}
	if (b[0] < b[1])
		do_op(context, op_sb);
	do_op(context, op_pa);
	do_op(context, op_sb);
	do_op(context, op_pa);
	do_op(context, op_sa);
	do_op(context, op_pa);
}

void	keep_in_a(t_stack_context *context, t_split *s)
{
	if (s->is_next)
	{
		do_op(context, op_rr);
		++s->rotate_b;
		s->is_next = 0;
	}
	else
		do_op(context, op_ra);
	++s->rotate_a;
}

void	send_to_b(t_stack_context *context, t_split *s)
{
	int	i;

	i = context->a->array[0];
	send_next(context, s);
	do_op(context, op_pb);
	if (s->had_elements)
	{
		s->is_next = 0;
		if (i >= s->p1)
			s->is_next = 1;
	}
	else
	{
		s->is_next = 0;
		if (i < s->p1)
			s->is_next = 1;
	}
}
