/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:16:09 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/19 20:44:28 by jsobreir         ###   ########.fr       */
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

#endif