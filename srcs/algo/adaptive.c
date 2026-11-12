/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:59:08 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/12 16:16:42 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	adaptive_sort(t_stack_context *context, float disorder)
{
	if (disorder < 0.2)
		simple_sort(context, disorder);
	else if (disorder < 0.5)
		medium_sort(context, disorder);
	else
		complex_sort(context, disorder);	
}

//on peut optimiser nos algos si on combine ces instructions en une seule
//si y a ra rb de suite ca devient un seul rr
//rra rrb devient rrr