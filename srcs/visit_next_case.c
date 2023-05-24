/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visit_next_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:23:47 by edufour           #+#    #+#             */
/*   Updated: 2023/05/24 14:40:13 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**copy_map(t_data *info)
{
	char **new_map;
	int	i;

	new_map = ft_calloc(info->map_height, sizeof(char *));
	i = -1;
	while (++i < info->map_height)
		new_map[i] = ft_strdup(info->map[i]);
	return (new_map);
}

void	visit_next_case(char **map, int x, int y)
{
	map[y][x] = 'V';
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'V')
		visit_next_case(map, x, y - 1);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'V')
		visit_next_case(map, x, y + 1);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'V')
		visit_next_case(map, x - 1, y);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'V')
		visit_next_case(map, x + 1, y);
}