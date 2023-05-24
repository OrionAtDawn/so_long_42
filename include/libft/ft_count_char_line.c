/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:25:01 by edufour           #+#    #+#             */
/*   Updated: 2023/05/17 13:54:54 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_char(char *line, char count)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (line[i])
		if (line[i++] == count)
			nb++;
	return (nb);
}
