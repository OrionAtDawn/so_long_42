/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:50:30 by edufour           #+#    #+#             */
/*   Updated: 2023/06/02 15:40:47 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_char(char *str, char check)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == check)
			return (0);
		i++;
	}
	return (1);
}
