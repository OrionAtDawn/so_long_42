/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:50:59 by edufour           #+#    #+#             */
/*   Updated: 2022/12/07 15:18:58 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return (((char *)s) + i);
		i++;
	}
	return (NULL);
}
