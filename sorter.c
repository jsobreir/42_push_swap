/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:55:55 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/04 20:03:48 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_price(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int	a_len;
	int	b_len;
	int	price;

	price = 1;
	a_len = stack_len(a);
	b_len = stack_len(b);
	if (pos_a <= a_len / 2)
		price += pos_a;
	else
		price += a_len - pos_a;
	if (pos_b <= b_len / 2)
		price += pos_b;
	else
		price += b_len - pos_b;
	return (price);
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->nbr;
	b = (*stack)->next->nbr;
	c = (*stack)->next->next->nbr;
	if ((a <= b && b < c) || (a < b && b <= c))
		return ;
	else if ((a > b && b > c) || (a > b && b >= c))
	{
		ft_swap(*stack, 'a');
		ft_reverse_rotate(stack, 'a');
	}
	else if ((a >= c && c > b) || (a > c && c >= b))
		ft_rotate(stack, 'a');
	else if ((b > a && a > c) || (b > a && a > c) || (a == b && b > c))
		ft_reverse_rotate(stack, 'a');
	else if ((b >= c && c > a) || (b > c && c >= a))
	{
		ft_swap(*stack, 'a');
		ft_rotate(stack, 'a');
	}
	else if ((c >= a && a > b) || (c > a && a >= b))
		ft_swap(*stack, 'a');
}

void	edge_cases(t_stack *a, t_stack *b)
{
	if (stack_len(a) == 1)
		exit(EXIT_SUCCESS);
	if (stack_len(a) == 3)
		sort_three(&a);
	else if (stack_len(a) == 4)
	{
		ft_push(&a, &b, 'b');
		sort_three(&a);
		pushback_to_a(&a, &b);
		move_smallest(&a);
	}
	else if (stack_len(a) == 5)
	{
		ft_push(&a, &b, 'b');
		ft_push(&a, &b, 'b');
		sort_three(&a);
		pushback_to_a(&a, &b);
		move_smallest(&a);
	}
	else if (stack_len(a) == 2 && a->nbr > a->next->nbr)
		ft_swap(a, 'a');
	exit(EXIT_SUCCESS);
}
