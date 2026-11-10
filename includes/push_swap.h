/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:17:30 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/10 11:29:35 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "../Libft/libft.h"

typedef struct	s_stack
{
	int	*array;
	int	size;
}	t_stack;

typedef enum	e_op
{
	op_sa,
	op_sb,
	op_ss,
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rr,
	op_rra,
	op_rrb,
	op_rrr
}	t_op;

typedef	struct s_context
{
	t_stack	*a;
	t_stack	*b;
}	t_context;


void	do_op(t_context context);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a);
void	pb(t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

int		ft_tablen(char **str);
int		no_error(int argc, char **argv);
void	free_split(int argc, char **argv);

void	print_split(char **str);
void	print_error();
int		no_error(int argc, char **argv);
int		ft_tablen(char **str);
void	free_split(int argc, char **argv);

#endif