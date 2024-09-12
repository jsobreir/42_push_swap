/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:56:03 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/06 19:17:47 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, char select)
{
	int	temp;

	temp = stack->next->nbr;
	stack->next->nbr = stack->nbr;
	stack->nbr = temp;
	if (select == 'a')
		ft_printf("sa\n");
	else if (select == 'b')
		ft_printf("sb\n");
}

void	ft_push(t_stack **from, t_stack **to, char to_select)
{
	t_stack	*to_free;
	t_stack	*new_node;

	if (*from == NULL)
		return ;
	new_node = ft_newstack((*from)->nbr);
	ft_stackadd_front(to, new_node);
	to_free = *from;
	*from = (*from)->next;
	free(to_free);
	if (to_select == 'a')
		ft_printf("pa\n");
	else if (to_select == 'b')
		ft_printf("pb\n");
}

void	ft_rotate(t_stack **stack, char select)
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
	if (select == 'a')
		ft_printf("ra\n");
	else if (select == 'b')
		ft_printf("rb\n");
}

void	ft_reverse_rotate(t_stack **stack, char select)
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
	if (select == 'a')
		ft_printf("rra\n");
	else if (select == 'b')
		ft_printf("rrb\n");
}
