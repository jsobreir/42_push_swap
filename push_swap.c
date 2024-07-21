/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:16:01 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/21 23:11:58 by jsobreir         ###   ########.fr       */
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

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	printf("----------------");
	printf("\nA\n---\n");
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
	printf("\nB\n---\n");
	while (stack_b)
	{
		printf("%d\n", stack_b->nbr);
		stack_b = stack_b->next;
	}
	printf("----------------\n");
}

int	target_in_b(t_stack *a, t_stack *b)
{
	int	number;
	int	index;
	
	number = a->nbr;
	index = 0;
	while (b != NULL && b->nbr > number)
	{
		b = b->next;
		index++;
	}
	return (index);
}

int	find_smallest(t_stack *stack)
{
	int	index;
	int	number;
	int	i;

	i = 0;
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

void	move(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	printf("pos_a = %d, pos_b = %d\n", pos_a, pos_b);
	while (pos_a || pos_b)
	{
		if (pos_a == 1 || pos_b == 1)
		{
			if (pos_a == 1)
			{
				ft_swap(*a);
				write(1, "sa\n", 3);
			}
			else
			{
				ft_swap(*b);
				write(1, "sb\n", 3);
			}
		}
		else if (pos_a <= stack_len(*a) / 2 && pos_b <= stack_len(*b) && pos_a && pos_b)
		{
			write(1, "rr\n", 3);
			ft_rotate(a);
			ft_rotate(b);
		}
		else if (pos_a > stack_len(*a) / 2 && pos_b > stack_len(*b) && pos_a && pos_b)
		{
			write(1, "rrr\n", 3);
			ft_reverse_rotate(a);
			ft_reverse_rotate(b);
		}
		else if (pos_a <= stack_len(*a) / 2 && pos_a && pos_b == 0)
		{
			ft_reverse_rotate(a);
			write(1, "rra\n", 4);
		}
		else if (pos_b <= stack_len(*b) && pos_a == 0 && pos_b)
		{
			ft_rotate(b);
			write(1, "rrb\n", 4);	
		}
	}
	ft_push(a, b);
	write(1, "pb\n", 3);	
}

void	turk_algorithm(t_stack *a, t_stack *b)
{
	int lowest_price_index;
	int	price;
	int	i;
	int	lowest_number;
	t_stack	*a_temp;
	
	a_temp = a;
	while (stack_len(a_temp))
	{
		print_stacks(a, b);
		a_temp = a;
		lowest_price_index = 0;
		i = 0;
		price = calculate_price(a, b, 0, target_in_b(a_temp, b));
		while (a_temp != NULL)
		{
			if (calculate_price(a, b, i, target_in_b(a_temp, b)) < price)
				lowest_price_index = i;
			i++;
			a_temp = a_temp->next;
		}
		move(&a, &b, lowest_price_index, target_in_b(a, b));
	}
	lowest_number = find_smallest(b);
	while (lowest_number-- && lowest_number <= stack_len(b) / 2)
		ft_rotate(&b);
	lowest_number = (stack_len(b) / 2) - lowest_number;
	while (lowest_number-- && lowest_number > stack_len(b) / 2)
		ft_reverse_rotate(&b);
	while (stack_len(b))
		ft_push(&b, &a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 2)
		return (0);
	a =  NULL;
	b = NULL;
	init_stacks(a, b);
	a = stack_args(a, argv);
	
	ft_push(&a, &b);
	ft_push(&a, &b);
	print_stacks(a, b);
	if (b->next->nbr < b->nbr)
		ft_swap(b);
	turk_algorithm(a, b);
	return (0);
}
