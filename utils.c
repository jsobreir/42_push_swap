/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:17:26 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/21 19:00:21 by jsobreir         ###   ########.fr       */
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