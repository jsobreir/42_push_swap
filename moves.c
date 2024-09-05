/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:30:19 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/04 19:48:00 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_both(t_stack **a, t_stack **b, int *pos_a, int *pos_b)
{
	while (*pos_a > 0 && *pos_b > 0 && *pos_a < stack_len(*a)
		&& *pos_b < stack_len(*b))
	{
		if (*pos_a <= stack_len(*a) / 2 && *pos_b <= stack_len(*b) / 2)
		{
			ft_rotate(a, 0);
			ft_rotate(b, 0);
			ft_printf("rr\n");
			(*pos_a)--;
			(*pos_b)--;
		}
		else if (*pos_a > stack_len(*a) / 2 && *pos_b > stack_len(*b) / 2)
		{
			ft_reverse_rotate(a, 0);
			ft_reverse_rotate(b, 0);
			ft_printf("rrr\n");
			(*pos_a)++;
			(*pos_b)++;
		}
		else
			break ;
	}
}

static void	ft_rotate_a(t_stack **a, t_stack **b, int pos_a, int bool)
{
	while (pos_a > 0 && pos_a < stack_len(*a))
	{
		if (pos_a <= stack_len(*a) / 2)
		{
			ft_rotate(a, 'a');
			pos_a--;
		}
		else
		{
			ft_reverse_rotate(a, 'a');
			pos_a++;
		}
	}
	if (bool == 1)
	{
		ft_push(b, a, 'a');
	}
}

static void	ft_rotate_b(t_stack **b, int pos_b)
{
	while (pos_b > 0 && pos_b < stack_len(*b))
	{
		if (pos_b <= stack_len(*b) / 2)
		{
			ft_rotate(b, 'b');
			pos_b--;
		}
		else
		{
			ft_reverse_rotate(b, 'b');
			pos_b++;
		}
	}
}

void	move(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	ft_rotate_both(a, b, &pos_a, &pos_b);
	ft_rotate_a(a, b, pos_a, 0);
	ft_rotate_b(b, pos_b);
	ft_push(a, b, 'b');
}

void	pushback_to_a(t_stack **a, t_stack **b)
{
	int		index;
	t_stack	*a_temp;

	while (*b)
	{
		a_temp = *a;
		index = 0;
		while (a_temp->next)
		{
			if ((*b)->nbr >= stack_get_index(*a, stack_largest(*a))
				|| (*b)->nbr <= stack_get_index(*a, stack_smallest(*a)))
			{
				index = stack_largest(*a) + 1;
				break ;
			}
			if (index == 0 && ((ft_stacklast(*a))->nbr
					<= (*b)->nbr && a_temp->nbr >= (*b)->nbr))
				break ;
			index++;
			if (a_temp->nbr <= (*b)->nbr && a_temp->next->nbr >= (*b)->nbr)
				break ;
			a_temp = a_temp->next;
		}
		ft_rotate_a(a, b, index, 1);
	}
}
