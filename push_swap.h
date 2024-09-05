/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:16:09 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/05 11:58:54 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

// Stack manipulation functions - stack.c
t_stack	*stack_args(t_stack *stack, char **argv, int argc);
t_stack	*ft_newstack(int nbr);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_stackadd_back(t_stack **stack, t_stack *new);
// Stack moves functions - basic_moves.c
void	ft_stackclear(t_stack *stack);
void	ft_swap(t_stack *stack, char select);
void	ft_push(t_stack **from, t_stack **to, char to_select);
void	ft_rotate(t_stack **stack, char select);
void	ft_reverse_rotate(t_stack **stack, char select);
// Stack moves functions extra - moves.c
void	move(t_stack **a, t_stack **b, int pos_a, int pos_b);
void	move_largest(t_stack **b);
void	move_smallest(t_stack **b);
void	pushback_to_a(t_stack **a, t_stack **b);
// Stack info functions - stack_info.c
int		stack_len(t_stack *stack);
int		stack_largest(t_stack *stack);
int		stack_smallest(t_stack *stack);
int		stack_get_index(t_stack *stack, int index);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
// Sorting Functions - sorting.c
int		calculate_price(t_stack *a, t_stack *b, int pos_a, int pos_b);
void	sort_three(t_stack **stack);
void	edge_cases(t_stack *a, t_stack *b);
// Utils
t_stack	*stack_args(t_stack *stack, char **argv, int argc);
void	init_stacks(t_stack *stack_a, t_stack *stack_b);

#endif