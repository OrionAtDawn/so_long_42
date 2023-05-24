/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:04:00 by edufour           #+#    #+#             */
/*   Updated: 2023/02/06 07:22:13 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	size_nb_string(int n)
{
	int	size_nb;

	size_nb = 1;
	while (n / 10 > 0)
	{
		size_nb++;
		n /= 10;
	}
	return (size_nb);
}

static char	*to_nb(int n, int size_nb, int sign, char *nb)
{
	int	i;

	i = size_nb + sign - 1;
	while (n >= 10)
	{
		nb[i--] = (n % 10) + 48;
		n /= 10;
	}
	nb[i--] = n + 48;
	if (size_nb != size_nb + sign && nb != 0)
		nb[i] = '-';
	return (nb);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648\0"));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	nb = ft_calloc (sign + size_nb_string(n) + 1, sizeof(char));
	if (!nb)
		return (NULL);
	return (to_nb(n, size_nb_string(n), sign, nb));
}
