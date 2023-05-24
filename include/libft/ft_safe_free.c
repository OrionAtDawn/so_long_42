/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:41:43 by edufour           #+#    #+#             */
/*   Updated: 2023/05/17 09:07:11 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*If it isn't NULL, frees '*to_free' and sets it to NULL, 
then returns 'return_value'.*/
int	safe_free(int return_value, void **to_free)
{
	if (to_free && *to_free)
	{	
		free (*to_free);
		*to_free = NULL;
	}
	return (return_value);
}
