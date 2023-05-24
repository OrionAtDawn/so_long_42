/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:51:16 by edufour           #+#    #+#             */
/*   Updated: 2022/12/07 15:57:05 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_hay;
	size_t	i_needle;

	i_hay = 0;
	if (!needle || !haystack)
		return (NULL);
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i_hay] && i_hay < len)
	{
		i_needle = 0;
		while (haystack[i_hay + i_needle] == needle[i_needle]
			&& i_hay + i_needle < len)
			if (needle [++i_needle] == '\0')
				return ((char *)haystack + i_hay);
		i_hay++;
	}
	return (NULL);
}
