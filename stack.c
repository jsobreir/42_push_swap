/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:29:33 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/19 15:17:58 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newstack(int nbr)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->next = NULL;
	return (node);
}

t_stack	*ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (stack == NULL)
		return (NULL);
	if (*stack == NULL)
	{
		*stack = new;
		return (*stack);
	}
	if (*stack && new)
	{
		new->next = *stack;
		*stack = new;
	}
	return (*stack);
}

t_stack	*ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack == NULL)
		return (NULL);
	if (*stack == NULL)
	{
		*stack = new;
		return (*stack);
	}
	last = ft_stacklast(*stack);
	last->next = new;
	return (*stack);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (!(stack->next))
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

void	ft_stackclear(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	stack = NULL;
}
