/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:47:25 by edufour           #+#    #+#             */
/*   Updated: 2022/12/08 12:28:30 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*cat;
	int		i_s1;
	int		i_s2;

	i_s1 = 0;
	i_s2 = 0;
	if (!s1 || !s2)
		return (NULL);
	cat = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!cat)
		return (NULL);
	while (s1[i_s1])
	{
		cat[i_s1] = s1[i_s1];
		i_s1++;
	}
	while (s2[i_s2])
	{
		cat[i_s1 + i_s2] = s2[i_s2];
		i_s2++;
	}
	cat[i_s1 + i_s2] = '\0';
	return (cat);
}
