/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:36:08 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/11 10:26:06 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_swap_push(t_stack_context *context, t_op op)
{
	if (op == op_sa)
		sa(context->a);
	else if (op == op_sb)
		sb(context->b);
	else if (op == op_ss)
		ss(context->a, context->b);
	else if (op == op_pa)
		pa(context->a, context->b);
	else if (op == op_pb)
		pb(context->a, context->b);
}

static void	exec_rotate(t_stack_context *context, t_op op)
{
	if (op == op_ra)
		ra(context->a);
	else if (op == op_rb)
		rb(context->b);
	else if (op == op_rr)
		rr(context->a, context->b);
	else if (op == op_rra)
		rra(context->a);
	else if (op == op_rrb)
		rrb(context->b);
	else if (op == op_rrr)
		rrr(context->a, context->b);
}

/* names[] doit rester dans le meme ordre que l'enum t_op */
void	do_op(t_stack_context *context, t_op op)
{
	static const char	*names[] = {"sa\n", "sb\n", "ss\n", "pa\n",
		"pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	if (op <= op_pb)
		exec_swap_push(context, op);
	else
		exec_rotate(context, op);
	write(1, names[op], ft_strlen(names[op]));
	context->operations_count[op]++;
}
