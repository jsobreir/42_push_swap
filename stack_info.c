/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:15:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/05 12:07:09 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	counter;

	counter = 0;
	while (stack != NULL)
	{
		counter++;
		stack = stack->next;
	}
	return (counter);
}

int	stack_largest(t_stack *stack)
{
	int	index;
	int	number;
	int	i;

	i = 0;
	index = 0;
	number = stack->nbr;
	while (stack != NULL)
	{
		if (stack->nbr >= number)
		{
			number = stack->nbr;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

int	stack_smallest(t_stack *stack)
{
	int	index;
	int	number;
	int	i;

	i = 0;
	index = 0;
	number = stack->nbr;
	while (stack != NULL)
	{
		if (stack->nbr < number)
		{
			number = stack->nbr;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

int	stack_get_index(t_stack *stack, int index)
{
	while (index > 0)
	{
		stack = stack->next;
		index--;
	}
	return (stack->nbr);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = stack_a;
	tmpb = stack_b;
	ft_printf("----------------");
	ft_printf("\nA\n---\n");
	while (tmpa != NULL)
	{
		ft_printf("%d\n", tmpa->nbr);
		tmpa = tmpa->next;
	}
	ft_printf("\nB\n---\n");
	while (tmpb != NULL)
	{
		ft_printf("%d\n", tmpb->nbr);
		tmpb = tmpb->next;
	}
	ft_printf("----------------\n");
}
