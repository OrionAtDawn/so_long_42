/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:51:05 by edufour           #+#    #+#             */
/*   Updated: 2023/01/06 10:50:00 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i_dst;
	size_t	i_src;
	size_t	size_dst;

	if (!dst || !src)
		return (0);
	size_dst = ft_strlen(dst);
	if (size_dst >= dstsize)
		return (dstsize + ft_strlen(src));
	i_dst = size_dst;
	i_src = 0;
	while (src[i_src] && i_dst < dstsize - 1)
			dst[i_dst++] = src[i_src++];
	dst[i_dst] = '\0';
	return (size_dst + (ft_strlen(src)));
}
