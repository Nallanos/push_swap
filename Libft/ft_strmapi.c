/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:49:10 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/04 17:02:13 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	i = -1;
	res = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (s[++i])
		res[i] = f(i, s[i]);
	return (res);
}
