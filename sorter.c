/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:55:55 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/03 14:41:54 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_price(t_stack *a, t_stack *b, int	pos_a, int pos_b)
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

static void	ft_rotate_comb(t_stack **a, t_stack **b, int *pos_a, int *pos_b)
{
	while (*pos_a > 0 && *pos_b > 0 && *pos_a < stack_len(*a) && *pos_b < stack_len(*b))
	{
		if (*pos_a <= stack_len(*a) / 2 && *pos_b <= stack_len(*b) / 2)
		{
			ft_rotate(a);
			ft_rotate(b);
			ft_printf("rr\n");
			(*pos_a)--;
			(*pos_b)--;
		}
		else if (*pos_a > stack_len(*a) / 2 && *pos_b > stack_len(*b) / 2)
		{
			ft_reverse_rotate(a);
			ft_reverse_rotate(b);
			ft_printf("rrr\n");
			(*pos_a)++;
			(*pos_b)++;
		}
		else
			break;
	}
}

void	move(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	ft_rotate_comb(a, b, &pos_a, &pos_b);
	while (pos_a > 0 && pos_a < stack_len(*a))
	{
		if (pos_a <= stack_len(*a) / 2)
		{
			ft_rotate(a);
			ft_printf("ra\n");
			pos_a--;
		}
		else
		{
			ft_reverse_rotate(a);
			ft_printf("rra\n");
			pos_a++;
		}
	}
	while (pos_b > 0 && pos_b < stack_len(*b))
	{
		if (pos_b <= stack_len(*b) / 2)
		{
			ft_rotate(b);
			ft_printf("rb\n");
			pos_b--;
		}
		else
		{
			ft_reverse_rotate(b);
			ft_printf("rrb\n");
			pos_b++;
		}
	}
	ft_push(a, b);
	ft_printf("pb\n");
}
