/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdess <moabdess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:10:44 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/14 14:25:05 by moabdess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(float disorder)
{
	int	nb;

	nb = (int)(disorder * 10000 + 0.5f);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(nb / 100, 2);
	ft_putstr_fd(".", 2);
	if (nb % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(nb % 100, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_strategy(t_exec_context exec_context)
{
	t_mode	current_mode;

	current_mode = exec_context.mode;
	ft_putstr_fd("[bench] strategy: ", 2);
	if (exec_context.mode == adaptive)
	{
		ft_putstr_fd("Adaptive / ", 2);
		current_mode = complex;
		if (exec_context.disorder < 0.2)
			current_mode = simple;
		else if (exec_context.disorder < 0.5)
			current_mode = medium;
	}
	else if (exec_context.mode == simple)
		ft_putstr_fd("Simple / ", 2);
	else if (exec_context.mode == medium)
		ft_putstr_fd("Medium / ", 2);
	else
		ft_putstr_fd("Complex / ", 2);
	if (current_mode == simple)
		ft_putstr_fd("O(n²)\n", 2);
	else if (current_mode == medium)
		ft_putstr_fd("O(n√n)\n", 2);
	else
		ft_putstr_fd("O(n log n)\n", 2);
}

void	print_count(char *str, int count, char *sep)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	ft_putstr_fd(sep, 2);
}

void	print_counts(int *c)
{
	ft_putstr_fd("[bench] ", 2);
	print_count("sa", c[op_sa], " ");
	print_count("sb", c[op_sb], " ");
	print_count("ss", c[op_ss], " ");
	print_count("pa", c[op_pa], " ");
	print_count("pb", c[op_pb], "\n");
	ft_putstr_fd("[bench] ", 2);
	print_count("ra", c[op_ra], " ");
	print_count("rb", c[op_rb], " ");
	print_count("rr", c[op_rr], " ");
	print_count("rra", c[op_rra], " ");
	print_count("rrb", c[op_rrb], " ");
	print_count("rrr", c[op_rrr], "\n");
}

void	print_bench(t_exec_context exec_context, t_stack_context *context)
{
	int	i;
	int	total;

	i = -1;
	total = 0;
	while (++i < 11)
		total += context->operations_count[i];
	print_disorder(exec_context.disorder);
	print_strategy(exec_context);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	print_counts(context->operations_count);
}
