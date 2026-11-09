/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:42:26 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/05 13:43:31 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	if (dest_tmp == src_tmp || n == 0)
		return (dest);
	i = -1;
	if (dest_tmp < src_tmp)
		while (++i < n)
			dest_tmp[i] = src_tmp[i];
	else
	{
		i = n;
		while (--i + 1 > 0)
			dest_tmp[i] = src_tmp[i];
	}
	return (dest);
}
