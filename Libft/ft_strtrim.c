/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:45:11 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/05 14:24:35 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char const *str, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (set[j] == '\0')
			break ;
		else if (str[i] == set[j])
		{
			++i;
			j = 0;
		}
		else
			++j;
	}
	return (i);
}

static int	find_end(char const *str, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = 0;
	while (i > 0)
	{
		if (set[j] == '\0')
			break ;
		else if (str[i] == set[j])
		{
			--i;
			j = 0;
		}
		else
			++j;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*res;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = find_start(s1, set);
	end = find_end(s1, set);
	len = (end - start) + 1;
	res = ft_substr(s1, start, len);
	return (res);
}
