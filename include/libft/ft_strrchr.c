/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:51:18 by edufour           #+#    #+#             */
/*   Updated: 2022/12/07 15:23:50 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen(s) + 1;
	while (--i >= 0)
		if (s[i] == (char)c)
			return (((char *)s) + i);
	return (NULL);
}
