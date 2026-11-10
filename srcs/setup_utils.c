/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:01:45 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/10 12:02:15 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_t_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->array)
			free(stack->array);
		free(stack);
	}
}
