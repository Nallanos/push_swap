/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenameu <abenameu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:17:30 by moabdess          #+#    #+#             */
/*   Updated: 2026/11/17 13:17:37 by abenameu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int	*array;
	int	size;
	int	capacity;
}	t_stack;

typedef enum e_op
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

typedef enum mode
{
	simple,
	medium,
	complex,
	adaptive,
	error,
	undefined
}	t_mode;

typedef struct stack_context
{
	t_stack	*a;
	t_stack	*b;
	int		operations_count[11];
}	t_stack_context;

typedef struct exec_context
{
	t_mode	mode;
	int		is_bench;
	float	disorder;
}	t_exec_context;

typedef struct s_split
{
	int	p1;
	int	p2;
	int	rotate_a;
	int	rotate_b;
	int	is_next;
	int	full;
	int	had_elements;
}	t_split;

void			do_op(t_stack_context *context, t_op op);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
int				ft_tablen(char **str);
int				no_error(char **input);
int				exit_on_error(char **input, t_stack_context *context);
void			free_split(int argc, char **argv);
void			print_split(char **str);
int				print_error(void);
int				ft_tablen(char **str);
void			free_split(int argc, char **argv);
void			free_t_stack(t_stack *stack);
t_stack_context	*setup_context(char **input);
void			free_t_stack_context(t_stack_context *context);
t_mode			get_mode(int argc, char **argv);
int				is_bench(int argc, char **argv);
t_exec_context	get_exec_context(int argc, char **argv);
int				has_blank_arg(int argc, char **argv);
char			*format_argv(int argc, char **argv);
int				ft_strcat(char *dest, const char *src);
long			ft_atol(const char *str);
float			get_disorder(int *input, int len);
void			simple_sort(t_stack_context *context, float disorder);
void			adaptive_sort(t_stack_context *context, float disorder);
void			medium_sort(t_stack_context *context);
void			complex_sort(t_stack_context *context, float disorder);
int				ft_sqrt(int nb);
void			pull_back(t_stack_context *context);
void			rotate_a(t_stack_context *ctx, int *rb_pending);
int				min(int a, int b);
void			push_to_b(t_stack_context *ctx, int mid, int *rb_pending);
int				find_max_index(t_stack *s);
int				index_stack(t_stack *stack);
void			print_bench(t_exec_context exec_context,
					t_stack_context *context);
void			quicksort_a(t_stack_context *context, int size);
void			quicksort_b(t_stack_context *context, int size);
void			send_next(t_stack_context *context, t_split *s);
void			partition_a(t_stack_context *context, int size);
void			partition_b(t_stack_context *context, int size);
void			sort_three_a(t_stack_context *context);
void			push_two_b(t_stack_context *context);
void			sort_three_b(t_stack_context *context);
void			keep_in_a(t_stack_context *context, t_split *s);
void			send_to_b(t_stack_context *context, t_split *s);

#endif