/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:50:01 by edufour           #+#    #+#             */
/*   Updated: 2022/12/19 08:03:29 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	index_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	if (!str)
		return (0);
	sign = 1;
	i = index_sign(str, &sign);
	num = 0;
	while (ft_isdigit(str[i]) != 0)
	{
		num *= 10;
		num = num + (int)str[i] - '0';
		i++;
	}
	return (num * sign);
}
