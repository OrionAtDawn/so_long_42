/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizenb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:18:02 by edufour           #+#    #+#             */
/*   Updated: 2023/01/13 11:51:03 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sizenb(unsigned long long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		size ++;
		n /= 10;
	}
	return (size);
}
