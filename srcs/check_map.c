/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:21:44 by edufour           #+#    #+#             */
/*   Updated: 2023/05/24 15:09:29 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_file(char *map_name, t_data *info)
{
	int	i;

	i = ft_strlen(map_name);
	if (i < 4 || map_name[--i] != 'r' || map_name[--i] != 'e'
		|| map_name[--i] != 'b' || map_name[--i] != '.')
		return (error_message("Wrong file extension."));
	info->fd = open(info->path, O_RDONLY);
	if (info->fd < 1)
	{
		close (info->fd);
		return (error_message("Invalid file."));
	}
	return (0);
}

int	check_elements(t_data *info)
{
	int	i_map;
	int	i_line;

	i_map = 0;
	while (i_map < info->map_height)
	{
		i_line = 0;
		while (i_line < info->map_lenght)
		{	
			if (info->map[i_map][i_line] != '0'
				&& info->map[i_map][i_line] != '1'
				&& info->map[i_map][i_line] != 'C'
				&& info->map[i_map][i_line] != 'E'
				&& info->map[i_map][i_line] != 'P'
				&& info->map[i_map][i_line] != '\0'
				&& info->map[i_map][i_line] != '\n')
				return (error_message("Unknown element found."));
			i_line ++;
		}
		i_map++;
	}
	if (char_count_sl(info, 'P') != 1 || char_count_sl(info, 'C') < 1
		|| char_count_sl(info, 'E') != 1)
		return (error_message("Number of elements invalid."));
	
	return (0);
}

int	check_walls(t_data *info)
{
	int	i_map;
	int	i_line;

	i_line = 0;
	if (compare_lenght(info) != 0)
		return (error_message("Map isn't rectangular."));
	if (ft_count_char(info->map[0], '1') != info->map_lenght
		|| ft_count_char(info->map[info->map_height - 1], '1')
		!= info->map_lenght)
		return (error_message("Map is not closed with walls."));
	i_map = 0;
	while (i_map < info->map_height)
		if (info->map[i_map][0] != '1'
		|| info->map[i_map++][info->map_lenght - 1] != '1')
			return (error_message("Map is not closed with walls."));
	return (0);
}

int	check_playable(t_data *info)
{
	char	**map_copy;
	int		i_map;
	int		i_line;

	i_map = -1;
	while (++i_map < info->map_height)
	{	
		i_line = -1;
		while (++i_line < info->map_lenght)
		{	
			if (info->map[i_map][i_line] == 'P')
			{
				info->position_x = i_map;
				info->position_y = i_line;
			}
		}
	}
	map_copy = copy_map(info);
	visit_next_case(info->map, info->position_y, info->position_x);
	if (char_count_sl(info, 'C') != 0)
		return (error_message("Cannot reach all collectables."));
	if (char_count_sl(info, 'E') != 0)
		return (error_message("Cannot reach exit."));
	free(info->map);
	info->map = map_copy;
	return (1);
}

int	check_map(char	*map_name, t_data *info)
{
	if (check_file(map_name, info) != 0)
		return (1);
	if (create_map(info) != 0)
		return (1);
	if (check_elements(info) != 0)
		return (1);
	if (check_walls(info) != 0)
		return (1);
	if (check_playable(info) != 0)
		return (1);
	return (0);
}
