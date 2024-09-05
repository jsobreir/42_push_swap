/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:17:26 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/04 19:57:05 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_args(t_stack *stack, char **argv, int argc)
{
	char	*temp;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv++;
	while (*argv)
	{
		temp = *argv;
		while (*temp)
		{
			if (*temp < '0' || *temp > '9')
			{
				ft_putstr_fd("Error\n", 1);
				exit(EXIT_FAILURE);
			}
			temp++;
		}
		ft_stackadd_back(&stack, ft_newstack(ft_atoi(*argv)));
		argv++;
	}
	return (stack);
}

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

void	move_largest(t_stack **b)
{
	int	largest_number;

	largest_number = stack_largest(*b);
	if (largest_number <= stack_len(*b) / 2)
		while (largest_number--)
			ft_rotate(b, 'b');
	else
	{
		while (largest_number < stack_len(*b))
		{
			ft_reverse_rotate(b, 'b');
			largest_number++;
		}
	}
}

void	move_smallest(t_stack **b)
{
	int	smallest_number;

	smallest_number = stack_smallest(*b);
	if (smallest_number <= stack_len(*b) / 2)
		while (smallest_number--)
			ft_rotate(b, 'a');
	else
	{
		while (smallest_number < stack_len(*b))
		{
			ft_reverse_rotate(b, 'a');
			smallest_number++;
		}
	}
}
