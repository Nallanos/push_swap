/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:45:54 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/05 14:40:32 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		while (s[i] && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				++nb;
			++i;
		}
	}
	return (nb);
}

static int	len_word(char const *s, char c, int index)
{
	int	i;
	int	nb;
	int	word_len;

	i = 0;
	nb = 0;
	word_len = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		while (s[i] && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				++nb;
			if (nb == index)
				++word_len;
			++i;
		}
	}
	return (word_len);
}

static char	*get_word(char const *s, char c, int index)
{
	char	*word;
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	nb = 0;
	word = ft_calloc(sizeof(char), len_word(s, c, index) + 1);
	if (!word)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			++i;
		while (s[i] && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				++nb;
			if (nb == index)
				word[j++] = s[i];
			++i;
		}
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**res;

	i = -1;
	res = ft_calloc(sizeof(char *), (count_words(s, c) + 1));
	if (!res || !s)
		return (NULL);
	while (++i < count_words(s, c))
	{
		res[i] = get_word(s, c, i + 1);
		if (!res[i])
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
	}
	return (res);
}
