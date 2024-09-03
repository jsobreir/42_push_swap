/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:16:01 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/03 14:28:37 by jsobreir         ###   ########.fr       */
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
	t_stack	*tmpa;
	t_stack	*tmpb;
	
	tmpa = stack_a;
	tmpb = stack_b;
	printf("----------------");
	printf("\nA\n---\n");
	while (tmpa != NULL)
	{
		printf("%d\n", tmpa->nbr);
		tmpa = tmpa->next;
	}
	printf("\nB\n---\n");
	while (tmpb)
	{
		printf("%d\n", tmpb->nbr);
		tmpb = tmpb->next;
	}
	printf("----------------\n");
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a =  (*stack)->nbr;
	b = (*stack)->next->nbr;
	c = (*stack)->next->next->nbr;
	if (a < b && b < c)
		return ;
	else if (a > b && b > c)
	{
		ft_swap(*stack);
		ft_reverse_rotate(stack);
		ft_printf("sa\nrra\n");
	}
	else if (a > c && c > b)
	{
		ft_rotate(stack);
		ft_printf("ra\n");
	}
	else if (b > a && a > c)
	{		
		ft_reverse_rotate(stack);
		ft_printf("rra\n");
	}
	else if (b > c && c > a)
	{
		ft_swap(*stack);
		ft_rotate(stack);
		ft_printf("sa\nra\n");
	}
	else if (c > a && a > b)
	{
		ft_swap(*stack);
		ft_printf("sa\n");
	}
}

int	target_in_b(t_stack *a, t_stack *b, int a_lowest_index)
{
	int	number;
	int	index;
	t_stack	*btmp;
	
	btmp = b;
	while (a_lowest_index--)
		a = a->next;
	number = a->nbr;
	index = 0;
	// Number is either the smallest or largest
	if (number >= stack_get_index(b, stack_largest(b)) 
		|| number <= stack_get_index(b, stack_smallest(b)))
		return (stack_largest(b));
	// else if (b->nbr >= number && ft_stacklast(b)->nbr <= number)
		// return (0);
	// Iterate through b to find the place where nbr is in between two other numbers
	else
	{
		index++;
		while (b->next)
		{
			if ((b->nbr >= number && b->next->nbr <= number))
				return (index);
			index++;
			b = b->next;
		}
	}
	return (0);
}

void	move_largest(t_stack **b)
{
	int	largest_number;

	largest_number = stack_largest(*b);
	if (largest_number <= stack_len(*b) / 2)
		while (largest_number--)
		{
			ft_printf("rb\n");
			ft_rotate(b);
		}
	else
	{
		while (largest_number < stack_len(*b))
		{
			ft_printf("rrb\n");
			ft_reverse_rotate(b);
			largest_number++;
		}
	}
}

void	turk_algorithm(t_stack *a, t_stack *b)
{
	t_stack	*a_temp;
	int lowest_price_index;
	int	price;
	int	i;
	
	a_temp = a;
	while (stack_len(a) > 0)
	{
		a_temp = a;
		lowest_price_index = 0;
		i = 0;
		price = calculate_price(a, b, 0, target_in_b(a_temp, b, 0));
		while (a_temp != NULL)
		{
			if (calculate_price(a, b, i, target_in_b(a_temp, b, 0)) < price)
			{
				lowest_price_index = i;
				price = calculate_price(a, b, i, target_in_b(a_temp, b, 0));
			}
			i++;
			a_temp = a_temp->next;
		}
		move(&a, &b, lowest_price_index, target_in_b(a, b, lowest_price_index));
		// print_stacks(a, b);
	}
	move_largest(&b);
	while (stack_len(b) > 0)
	{
		ft_push(&b, &a);
		ft_printf("pa\n");
	}
	// print_stacks(a, b);
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
	if (argc == 4)
	{
		sort_three(&a);
		return (0);
	}
	else if (argc == 3)
	{
		if (a->nbr > a->next->nbr)
		{
			ft_swap(a);
			ft_printf("sa\n");
			return (0);
		}
		else
			return (0);
	}
	ft_push(&a, &b);
	ft_push(&a, &b);
	ft_printf("pb\npb\n");
	if (b->next->nbr > b->nbr)
	{
		ft_swap(b);
		ft_printf("sb\n");
	}
	// print_stacks(a, b);
	turk_algorithm(a, b);
	return (0);
}
