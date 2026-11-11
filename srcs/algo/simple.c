/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:29:08 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/11 12:02:05 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min_index(t_stack *s)
{
	int	i;
	int index;
	int	value;

	i = 0;
	value = s->array[0]; 
	index = 0;
	while (i < s->size)
	{
		if (s->array[i] < value)
		{
			value = s->array[i];
			index = i;
		}
		i++;
	}	
	return (index);
}

void	bring_to_top(t_stack *s, t_stack_context *context)
{
	int	min_index;

	min_index = find_min_index(s);
	if (min_index <= s->size - min_index)
	{
		while (min_index > 0)
		{
			do_op(context, op_ra);
			min_index--;
		}
	}
	else
	{
		while (min_index < s->size)
		{
			do_op(context, op_rra);
			min_index++;
		}
	}
}

void	simple_sort(t_stack_context *context, float disorder)
{
	if (disorder == 0.0)
		return ;
	while (context->a->size > 0)
	{
		bring_to_top(context->a, context);
		do_op(context, op_pb);
	}
	while (context->b->size > 0)
	{
		do_op(context, op_pa);
	}
}
