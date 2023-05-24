/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:16:47 by edufour           #+#    #+#             */
/*   Updated: 2022/12/08 14:45:12 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	char		*result;

	if (!s)
		return (ft_strdup(""));
	if (!f)
		return (ft_strdup(s));
	result = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
