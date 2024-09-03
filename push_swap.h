/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:16:09 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/03 11:20:10 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_stack
{
	int		nbr;
	int		largest;
	struct s_stack	*next;
}				t_stack;

t_stack	*stack_args(t_stack *stack, char **argv);
t_stack	*ft_newstack(int nbr);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack *stack);
void	ft_swap(t_stack *stack);
void 	ft_push(t_stack **from, t_stack **to);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
void	move_largest(t_stack **b);
void	move(t_stack **a, t_stack **b, int pos_a, int pos_b);
int		stack_len(t_stack *stack);
int		calculate_price(t_stack *a, t_stack *b, int	pos_a, int pos_b);
int		stack_get_index(t_stack *stack, int index);
int		stack_largest(t_stack *stack);
int		stack_smallest(t_stack *stack);


#endif