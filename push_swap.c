/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:16:01 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/19 20:26:53 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a = malloc(sizeof(t_stack *));
	if (!stack_a)
		return ;
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_b)
	{
		free(stack_a);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 2)
		return (0);
	stack_a =  NULL;
	stack_b = NULL;
	init_stacks(stack_a, stack_b);
	stack_a = stack_args(stack_a, argv);
	ft_reverse_rotate(&stack_a);
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
	printf("\n\n");
	while (stack_b)
	{
		printf("%d\n", stack_b->nbr);
		stack_b = stack_b->next;
	}
}
