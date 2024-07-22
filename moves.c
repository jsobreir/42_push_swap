/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:56:03 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/22 14:35:37 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	temp;
	
	temp = stack->next->nbr;
	stack->next->nbr = stack->nbr;
	stack->nbr = temp;
}

void ft_push(t_stack **from, t_stack **to)
{
    t_stack *to_free;
    
    if (*from == NULL)
        return;

    ft_stackadd_front(to, ft_newstack((*from)->nbr));
    to_free = *from;
    *from = (*from)->next;
    free(to_free);
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*lst;
	long	number;

	number = (*stack)->nbr;
	lst = *stack;
	while (lst != NULL)
	{
		if (lst->next == NULL)
			lst->nbr = number;
		else
			lst->nbr = lst->next->nbr;
		lst = lst->next;
	}
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_to_last;

	second_to_last = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		second_to_last = last;
		last = last->next;
	}
	second_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
