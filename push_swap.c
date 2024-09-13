/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:16:01 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/13 12:00:21 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicated(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				error(argv, argc);
			j++;
		}
		i++;
	}
	return (0);
}

static void	check_ordered(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp->next)
	{
		if (temp->nbr > temp->next->nbr)
		{
			break ;
		}
		temp = temp->next;
	}
	if (temp->next == NULL)
	{
		ft_stackclear(a);
		exit(EXIT_SUCCESS);
	}
}

int	target_in_b(t_stack *a, t_stack *b, int a_lowest_index)
{
	int		number;
	int		index;

	while (a_lowest_index--)
		a = a->next;
	number = a->nbr;
	index = 0;
	if (number >= stack_get_index(b, stack_largest(b))
		|| number <= stack_get_index(b, stack_smallest(b)))
		index = stack_largest(b);
	else if ((ft_stacklast(b))->nbr >= number && b->nbr <= number)
		index = 0;
	else
	{
		index++;
		while (b->next)
		{
			if ((b->nbr >= number && b->next->nbr <= number))
				break ;
			index++;
			b = b->next;
		}
	}
	return (index);
}

static void	turk_algorithm(t_stack **a, t_stack **b)
{
	t_stack	*a_temp;
	int		price;
	int		i;
	int		lowest_price_index;

	a_temp = *a;
	while (stack_len(*a) > 3)
	{
		a_temp = *a;
		lowest_price_index = 0;
		i = 0;
		price = calculate_price(*a, *b, 0, target_in_b(a_temp, *b, 0));
		while (a_temp != NULL)
		{
			if (calculate_price(*a, *b, i, target_in_b(a_temp, *b, 0)) < price)
			{
				lowest_price_index = i;
				price = calculate_price(*a, *b, i, target_in_b(a_temp, *b, 0));
			}
			i++;
			a_temp = a_temp->next;
		}
		move(a, b, lowest_price_index, target_in_b(*a, *b, lowest_price_index));
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || *argv[1] == '\0')
		return (0);
	a = NULL;
	b = NULL;
	a = stack_args(a, argv, argc);
	if (!a)
		exit(EXIT_FAILURE);
	check_ordered(&a);
	if (stack_len(a) <= 5)
		edge_cases(a, b);
	ft_push(&a, &b, 'b');
	ft_push(&a, &b, 'b');
	if (b->next->nbr > b->nbr)
		ft_swap(b, 'b');
	turk_algorithm(&a, &b);
	sort_three(&a);
	move_largest(&b);
	pushback_to_a(&a, &b);
	move_smallest(&a);
	ft_stackclear(&a);
	ft_stackclear(&b);
}
