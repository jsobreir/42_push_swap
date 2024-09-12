/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:17:26 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/11 19:09:32 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char **args, int argc)
{
	ft_putstr_fd("Error\n", 1);
	if (argc == 2)
		ft_free_array(args);
	exit(EXIT_FAILURE);
}

static void	check_args(char **args, int argc)
{
	long	num;
	int		len;
	char	*current_arg;
	char	**temp;

	len = 0;
	temp = args;
	while (*args)
	{
		num = ft_atol(*args);
		if (num < INT_MIN || num > INT_MAX)
			error(temp, argc);
		current_arg = *args;
		if (*current_arg == '-' || *current_arg == '+')
			current_arg++;
		while (*current_arg)
		{
			if (*current_arg < '0' || *current_arg > '9')
				error(temp, argc);
			current_arg++;
		}
		args++;
		len++;
	}
	check_duplicated(argc, temp);
}

t_stack	*stack_args(t_stack *stack, char **argv, int argc)
{
	char		**args;
	char		**temp;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (NULL);
		temp = args;
	}
	else
		args = argv + 1;
	check_args(args, argc);
	while (*args)
	{
		if (!ft_stackadd_back(&stack, ft_newstack(ft_atoi(*args))))
			return (ft_stackclear(&stack), NULL);
		args++;
	}
	if (argc == 2)
		ft_free_array(temp);
	return (stack);
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
