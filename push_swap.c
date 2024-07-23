/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:16:01 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/23 22:33:58 by jsobreir         ###   ########.fr       */
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
	printf("--------Current Stack--------");
	printf("\n A          B\n");
	printf("---        ---\n");
	while (stack_a  || stack_b)
	{
		if (stack_a && stack_b)
		{
			printf("%d         %d \n", stack_a->nbr, stack_b->nbr);
			stack_a = stack_a->next;
			stack_b = stack_b->next;
		}
		else if (stack_a && stack_b == NULL)
		{
			printf("%d          \n", stack_a->nbr);
			stack_a = stack_a->next;
		}
		else if (stack_a == NULL && stack_b)
		{
			printf("            %d\n", stack_b->nbr);
			stack_b = stack_b->next;
		}
	}
}

int	target_in_b(t_stack *a, t_stack *b)
{
	int	number;
	int	index;
	t_stack	*temp;
	
	temp = b;
	number = a->nbr;
	index = 0;
	while (temp != NULL)
	{
		if (temp->nbr < number)
			break;
		temp = temp->next;
		index++;
	}
	return (index);
}

int	find_largest(t_stack *stack)
{
	int	index;
	int	number;
	int	i;
	t_stack	*temp;

	i = 0;
	temp = stack;
	number = stack->nbr;
	while (temp != NULL)
	{
		if (temp->nbr >= number)
		{
			number = temp->nbr;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

void	move(t_stack **a, t_stack **b, int pos_a, int pos_b)
{	
	// printf("-------- MOVES --------\n");
	// printf("pos_a = %d, pos_b = %d\n", pos_a, pos_b);
	if (pos_a <= stack_len(*a) / 2 && pos_b <= stack_len(*b) / 2)
		while (pos_a && pos_b )
		{
			ft_rotate(a);
			ft_rotate(b);
			write(1, "rrr\n", 4);
			pos_a--;
			pos_b--;
		}
	if (pos_a > stack_len(*a) / 2 && pos_b > stack_len(*b) / 2 && pos_a && pos_b)
		while (pos_a < stack_len(*a) && pos_b < stack_len(*b))
		{
			write(1, "rrr\n", 4);
			ft_reverse_rotate(a);
			ft_reverse_rotate(b);
			pos_a++;
			pos_b++;
		}
	if (pos_a <= stack_len(*a) / 2 && pos_b == 0)
		while (pos_a)
		{
			ft_rotate(a);
			write(1, "ra\n", 3);
			pos_a--;
		}
	if (pos_b <= stack_len(*b) / 2 && pos_a == 0)
		while (pos_b)
		{
			ft_rotate(b);
			write(1, "rb\n", 3);
			pos_b--;
		}
	if (pos_a > stack_len(*a) / 2 && pos_a && pos_b == 0)
		while (pos_a < stack_len(*a))
		{
			ft_reverse_rotate(a);
			write(1, "rra\n", 4);
			pos_a++;
		}
	if (pos_b > stack_len(*b) / 2 && pos_b && pos_a == 0)
		while (pos_b <= stack_len(*b))
		{
			ft_reverse_rotate(b);
			write(1, "rrb\n", 4);
			pos_b++;
		}
	ft_push(a, b);
	write(1, "pb\n", 3);
	move_largest(b);
}

void	move_largest(t_stack **b) {
    int largest_index;

	largest_index = find_largest(*b);
    // printf("largest index = %d\n", largest_index);

    if (largest_index <= stack_len(*b) / 2)
	{
        while (largest_index--)
		{
            ft_rotate(b);
            write(1, "rb\n", 3);
        }
    }
	else
	{
        while (largest_index++ < stack_len(*b))
		{
            ft_reverse_rotate(b);
            write(1, "rrb\n", 4);
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
	while (stack_len(a))
	{
		a_temp = a;
		lowest_price_index = 0;
		i = 0;
		price = calculate_price(a, b, 0, target_in_b(a_temp, b));
		while (a_temp != NULL)
		{
			if (calculate_price(a, b, i, target_in_b(a_temp, b)) < price)
			{
				lowest_price_index = i;
				price = calculate_price(a, b, i, target_in_b(a_temp, b));
			}
			i++;
			a_temp = a_temp->next;
		}
		move(&a, &b, lowest_price_index, target_in_b(a, b));
		// print_stacks(a, b);
	}
	while (stack_len(b))
	{
		ft_push(&b, &a);
		write(1, "pa\n", 3);
	}
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
	
	ft_push(&a, &b);
	ft_push(&a, &b);
	write(1, "pb\npb\n", 6);
	if (b->next->nbr > b->nbr)
		ft_swap(b);
	turk_algorithm(a, b);
	return (0);
}
// int	main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	if (argc <= 2)
// 		return (0);
// 	a =  NULL;
// 	b = NULL;
// 	init_stacks(a, b);
// 	a = stack_args(a, argv);
	
// 	ft_push(&a, &b);
// 	ft_push(&a, &b);
// 	write(1, "pb\npb\n", 6);
// 	if (b->next->nbr > b->nbr)
// 		ft_swap(b);
// 	print_stacks(a, b);
// 	ft_rotate(&b);
// 	print_stacks(a, b);
// 	ft_push(&a, &b);
// 	print_stacks(a, b);
// 	ft_reverse_rotate(&b);
// 	print_stacks(a, b);
// 	// turk_algorithm(a, b);
// 	return (0);
// }
