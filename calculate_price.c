/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_price.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:55:55 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/22 15:12:10 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_price(t_stack *a, t_stack *b, int	pos_a, int pos_b)
{
	int	a_len;
	int	b_len;
	int	price;

	price = 0;
	a_len = stack_len(a);
	b_len = stack_len(b);
	if (pos_a <= a_len / 2)
		price += pos_a;
	else
		price += a_len - pos_a;
	if (pos_b <= b_len / 2)
		price += b_len;
	else
		price += b_len - pos_b;
	return (price);
}
