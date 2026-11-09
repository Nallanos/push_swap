/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:03:32 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/02 15:10:19 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	i = -1;
	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	while (++i < n)
	{
		if (!(s1_cpy[i] == s2_cpy[i]))
			return (s1_cpy[i] - s2_cpy[i]);
	}
	if (i >= n)
		return (0);
	return (s1_cpy[i] - s2_cpy[i]);
}
