/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:21:13 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/11 10:41:35 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack *dst, t_stack *src)
{
	int	i;
	int	tmp;
	
	if (src->size == 0)
		return ;
	if (dst->size >= dst->capacity)
		return ;
	tmp = src->array[0];
	i = 0;
	while (i < src->size - 1)
	{
		src->array[i] = src->array[i + 1];
		i++;
	}
	src->size--;
	i = dst->size;
	while (i > 0)
	{
		dst->array[i] = dst->array[i - 1];
		i--;
	}
	dst->array[0] = tmp;
	dst->size++;
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
}
