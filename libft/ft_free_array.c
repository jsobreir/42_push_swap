/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:33:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/13 14:15:35 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **array)
{
	int	size;

	size = 0;
	if (!array && *array == NULL)
		return ;
	while (array[size])
	{
		free(array[size]);
		size++;
	}
	free(array);
	return ;
}
