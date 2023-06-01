/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:16:51 by edufour           #+#    #+#             */
/*   Updated: 2023/06/01 14:19:44 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_free(t_data *info)
{
	int	i_map;

	i_map = 0;
	if (info->map)
	{
		while (i_map < info->map_height)
		{		
			if (info->map[i_map])
				{	
					free (info->map[i_map]);
					info->map[i_map] = NULL;
				}
			i_map++;
		}
		free(info->map);
		info->map = NULL;
	}
}