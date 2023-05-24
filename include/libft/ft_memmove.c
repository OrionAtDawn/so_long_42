/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:50:53 by edufour           #+#    #+#             */
/*   Updated: 2023/04/21 11:12:00 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//why is temp_src allocated ?

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*temp_src;
	size_t	i;

	if (!dst || !src)
		return (dst);
	temp_src = ft_calloc(sizeof(char), len);
	if (!temp_src)
		return (dst);
	i = 0;
	while (i < len)
	{
		((char *)temp_src)[i] = ((char *)src)[i];
		i++;
	}
	ft_memcpy(dst, temp_src, len);
	free(temp_src);
	return (dst);
}
