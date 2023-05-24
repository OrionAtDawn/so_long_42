/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:51:09 by edufour           #+#    #+#             */
/*   Updated: 2022/12/07 14:37:12 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size_src;

	if (!dst || !src)
		return (0);
	size_src = ft_strlen(src);
	if (dstsize > size_src + 1)
		ft_memcpy(dst, src, size_src + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, (char *)src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (size_src);
}
