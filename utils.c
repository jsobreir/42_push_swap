/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:17:26 by jsobreir          #+#    #+#             */
/*   Updated: 2024/08/28 21:26:14 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_args(t_stack *stack, char **argv)
{
	argv++;
	while (*argv)
	{
		ft_stackadd_back(&stack, ft_newstack(ft_atoi(*argv)));
		argv++;
	}
	return (stack);
}

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
		if (stack->nbr > number)
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