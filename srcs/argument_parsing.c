/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:28:22 by abenameu          #+#    #+#             */
/*   Updated: 2026/11/10 15:46:59 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_blank(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	has_blank_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && argv[i][1] == '-') && is_blank(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*alloc_formated_argv(int argc, char **argv)
{
	int		i;
	int		len;
	char	*result;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len += ft_strlen(argv[i]) + 1; 
		i++;
	}
	result = malloc(len);
	if (!result)
		return (NULL);
	result[0] = '\0';
	return (result);
}

char	*concat_argv(int argc, char **argv)
{
	int		i;
	char	*result;

	result = alloc_formated_argv(argc, argv);
	if (!result)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			i++;
			continue;
		}
		ft_strcat(result, argv[i]);
		if (i < argc - 1)
			ft_strcat(result, " ");
		i++;
	}
	return (result);
}

char	*format_argv(int argc, char **argv)
{
	char	*result;
	
	if (has_blank_arg(argc, argv) == 1)
		return (NULL);
	result = concat_argv(argc, argv);
	if (!result)
		return (NULL);
	return (result);
}
