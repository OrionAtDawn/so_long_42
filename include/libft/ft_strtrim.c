/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:46:33 by edufour           #+#    #+#             */
/*   Updated: 2022/12/08 12:44:33 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char *set)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(set);
	while (i < size)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*trim;
	size_t	i_start;
	size_t	i_end;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == 0)
		return (ft_strdup(s1));
	i_start = 0;
	while (is_set(s1[i_start], (char *)set) == 1)
		i_start++;
	if (i_start == ft_strlen(s1))
		return (ft_strdup(""));
	i_end = ft_strlen(s1);
	while (is_set(s1[i_end - 1], (char *)set) == 1)
		i_end--;
	trim = malloc((i_end - i_start) + 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[i_start], (i_end - i_start) + 1);
	return (trim);
}
