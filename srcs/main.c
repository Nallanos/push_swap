/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:30:00 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/11 16:07:04 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	exit_if_only_flags(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && argv[i][1] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	push_swap(t_exec_context exec_context, char **input)
{
	t_stack_context	*context;

	context = setup_context(input);
	if (!context)
		return (0);
	exec_context.disorder = get_disorder(context->a->array, context->a->size);
	if (exec_context.disorder == 0)
	{
		free_t_stack_context(context);
		return (1);
	}
	if (exec_context.mode == simple)
		simple_sort(context, exec_context.disorder);
	else if (exec_context.mode == medium)
		medium_sort(context, exec_context.disorder);
	else if (exec_context.mode == complex)
		complex_sort(context, exec_context.disorder);
	else if (exec_context.mode == adaptive)
		adaptive_sort(context, exec_context.disorder);
	free_t_stack_context(context);
	return (1);
}

int handle_arguments(int argc, char **argv, t_exec_context *exec_context, char ***input)
{
	char *formatted_argv;

	*exec_context = get_exec_context(argc, argv);
	formatted_argv = format_argv(argc, argv);
	if (!formatted_argv)
		return (0);
	*input = ft_split(formatted_argv, ' ');
	free(formatted_argv);
	if (!no_error(*input))
	{
		free_split(2, *input);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char			**input;
	t_exec_context	exec_context;

	if (argc < 2)
		return (0);
	if (exit_if_only_flags(argc, argv))
		return (print_error());
	if (!handle_arguments(argc, argv, &exec_context, &input))
		return (print_error());
	if (exec_context.mode == error)
		return (exit_on_error(input, NULL));
	push_swap(exec_context, input);
	free_split(2, input);
}
