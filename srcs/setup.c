/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:54:47 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/10 16:15:58 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_t_stack_context(t_stack_context *context)
{
	if (context)
	{
		free_t_stack(context->a);
		free_t_stack(context->b);
		free(context);
	}
}

int	fill_stack_array(char **input, t_stack *stack)
{
	int	i;
	int	array_size;

	array_size = stack->size; 
	i = 0;
	if (!array_size)
		return (0);
	stack->array = malloc(sizeof(int) * array_size);
	if (!stack->array)
		return (0);
	while (i < array_size && input)
	{
		(stack->array)[i] = ft_atoi(input[i]);
		i++;
	}
	return (1);
}

t_stack	*create_stack(char **input, int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = size;
	if (!fill_stack_array(input, stack))
	{
		free_t_stack(stack);
		return (NULL);
	}
	return (stack);
}

t_stack_context	*setup_context(char **input)
{
	t_stack 	*stack_a;
	t_stack 	*stack_b;
	t_stack_context	*context;

	stack_a = create_stack(input, ft_tablen(input));
	if (!stack_a)
		return (NULL);
	stack_b = create_stack(NULL, stack_a->size);
	if (!stack_b)
	{
		free_t_stack(stack_a);
		return (NULL);
	}
	context = malloc(sizeof(t_stack_context));
	if (!context)
	{
		free_t_stack(stack_a);
		free_t_stack(stack_b);
		return (NULL);
	}
	context->a = stack_a;
	context->b = stack_b;
	return (context);
}
