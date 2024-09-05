/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:42:56 by jsobreir          #+#    #+#             */
/*   Updated: 2024/09/05 12:07:49 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}

// int main(void)
// {
// 	ft_printf("%d\n", ft_atoi("	5748g"));
// 	ft_printf("%d\n", atoi("	5748g"));
// 	ft_printf("\n");
// 	ft_printf("%d\n", ft_atoi("  - 5748g"));
// 	ft_printf("%d\n", atoi("  - 5748g"));
// 	ft_printf("\n");
// 	ft_printf("%d\n", ft_atoi("++5748g"));
// 	ft_printf("%d\n", atoi("++5748g"));
// 	ft_printf("\n");
// 	ft_printf("%d\n", ft_atoi("+-5d748g"));
// 	ft_printf("%d\n", atoi("+-5d748g"));
// 	ft_printf("\n");
//	ft_printf("%d\n", ft_atoi("\v5748"));
// 	ft_ntf("%d\n", atoi("\v5748"));
// 	ft_ntf("\n");
//	ft_printf("%d\n", ft_atoi("-5748"));
// 	ft_ntf("%d\n", atoi("-5748"));
// 	ft_ntf("\n");
//	ft_printf("%d\n", ft_atoi("57s48g"));
// 	ft_printf("%d\n", atoi("57s48g"));
//