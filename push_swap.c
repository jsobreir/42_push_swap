/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:16:01 by jsobreir          #+#    #+#             */
/*   Updated: 2024/08/28 21:24:19 by jsobreir         ###   ########.fr       */
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

int	target_in_b(t_stack *a, t_stack *b)
{
	int	number;
	int	index;
	t_stack	*btmp;
	
	btmp = b;
	number = a->nbr;
	index = 0;
	if (number >= stack_largest(b) || number <= stack_smallest(b))
		return (stack_get_index(b, stack_largest(b)));
	else if ((number > b->nbr && number < ft_stacklast(b)->nbr) ||
		(number < b->nbr && number > ft_stacklast(b)->nbr))
		return (0);
	else
	{
		index++;
		while (b->next)
		{
			if ((b->nbr >= number && b->next->nbr <= number) || 
				(b->nbr <= number && b->next->nbr >= number))
				return (index);
			index++;
			b = b->next;
		}
	}
	return (0);
}

void	move(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	printf("pos_a = %d, pos_b = %d\n", pos_a, pos_b);
	while (pos_a > 0 || pos_b > 0)
	{
		if (pos_a <= stack_len(*a) / 2 && pos_b <= stack_len(*b) && pos_a && pos_b)
		{
			ft_rotate(a);
			ft_rotate(b);
			write(1, "rrr\n", 4);
			pos_a--;
			pos_b--;
		}
		else if (pos_a > stack_len(*a) / 2 && pos_b > stack_len(*b) && pos_a && pos_b)
		{
			write(1, "rrr\n", 3);
			ft_reverse_rotate(a);
			ft_reverse_rotate(b);
			pos_a--;
			pos_b--;
		}
		else if (pos_a <= stack_len(*a) / 2 && pos_a && pos_b == 0)
		{
			ft_rotate(a);
			write(1, "ra\n", 4);
			pos_a--;
		}
		else if (pos_a > stack_len(*a) / 2 && pos_a && pos_b == 0)
		{
			ft_reverse_rotate(a);
			write(1, "rra\n", 4);
			pos_a--;
		}
		else if (pos_b <= stack_len(*b) && pos_a == 0 && pos_b)
		{
			ft_rotate(b);
			write(1, "rb\n", 4);
			pos_b--;
		}
		else if (pos_b > stack_len(*b) && pos_a == 0 && pos_b)
		{
			ft_reverse_rotate(b);
			write(1, "rrb\n", 4);
			pos_b--;
		}
	}
	ft_push(a, b);
	write(1, "pb\n", 3);
}

void	move_largest(t_stack *b)
{
	int	largest_number;
	
	largest_number = stack_largest(b);
	if (largest_number <= stack_len(b) / 2)
		while (largest_number--)
		{
			write(1, "rb\n", 3);
			ft_rotate(&b);
		}
	else
	{
		while (largest_number <= stack_len(b))
		{
			write(1, "rrb\n", 4);
			ft_reverse_rotate(&b);
			largest_number++;
		}
	}
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a =  stack->nbr;
	b = stack->next->nbr;
	c = stack->next->next->nbr;
	if (a < b && b < c)
		return ;
	else if (a > b && b > c)
	{
		ft_swap(stack);
		write(1, "sa\nrra\n", 7);
		ft_reverse_rotate(&stack);
	}
	else if (a > c && c > b)
	{
		ft_rotate(&stack);
		write(1, "ra\n", 3);
	}
	else if (b > a && a > c)
	{		
		ft_reverse_rotate(&stack);
		write(1, "rra\n", 4);
	}
	else if (b > c && c > a)
	{
		ft_swap(stack);
		write(1, "sa\nra\n", 6);
		ft_rotate(&stack);
	}
	else if (c > a && a > b)
	{
		ft_swap(stack);
		write(1, "sa\n", 3);
	}
}

void	turk_algorithm(t_stack *a, t_stack *b)
{
	t_stack	*a_temp;
	int lowest_price_index;
	int	price;
	int	i;
	
	printf("%d\n%d\n", stack_largest(b), stack_smallest(b));
	a_temp = a;
	while (stack_len(a) > 3)
	{
		// printf("Here\n");
		a_temp = a;
		lowest_price_index = 0;
		i = 0;
		// printf("Here\n");
		price = calculate_price(a, b, 0, target_in_b(a_temp, b));
		while (a_temp != NULL)
		{
			if (calculate_price(a, b, i, target_in_b(a_temp, b)) < price)
				lowest_price_index = i;
			printf("price of index %d = %d\n", i, calculate_price(a, b, i, target_in_b(a_temp, b)));
			// printf("HEre:");
			i++;
			a_temp = a_temp->next;
		}
		// printf("Here\n");
		move(&a, &b, lowest_price_index, target_in_b(a, b));
		print_stacks(a, b);
	}
	print_stacks(a, b);
	sort_three(a);
	print_stacks(a, b);
	while (stack_len(b) > 0)
		ft_push(&b, &a);
	print_stacks(a, b);
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
		sort_three(a);
		return (0);
	}
	else if (argc == 3)
	{
		if (a->nbr > a->next->nbr)
		{
			ft_swap(a);
			write(1, "sa\n", 3);
			return (0);
		}
		else
			return (0);
	}
	ft_push(&a, &b);
	ft_push(&a, &b);
	write(1, "pb\npb\n", 6);
	if (b->next->nbr > b->nbr)
	{
		ft_swap(b);
		write(1, "sb\n", 3);
	}
	turk_algorithm(a, b);
	return (0);
}
