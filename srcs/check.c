/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:21:44 by edufour           #+#    #+#             */
/*   Updated: 2023/06/02 13:31:40 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_file(char *map_name, t_data *info)
{
	int	i;

	i = ft_strlen(map_name);
	if (i < 4 || map_name[--i] != 'r' || map_name[--i] != 'e'
		|| map_name[--i] != 'b' || map_name[--i] != '.')
		error_message("Wrong file extension.", info);
	info->fd = open(info->path, O_RDONLY);
	if (info->fd < 1)
	{
		close (info->fd);
		error_message("Invalid file.", info);
	}
}

void	check_elements(t_data *info)
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
				error_message("Unknown element found.", info);
			i_line ++;
		}
		i_map++;
	}
	if (char_count_sl(info->map, info, 'P') != 1
		|| char_count_sl(info->map, info, 'C') < 1
		|| char_count_sl(info->map, info, 'E') != 1)
		error_message("Number of elements invalid.", info);
	info->collectables = char_count_sl(info->map, info, 'C');
}

void	check_walls(t_data *info)
{
	int	i_map;
	int	i_line;

	i_line = 0;
	if (compare_lenght(info) != 0)
		error_message("Map isn't rectangular.", info);
	if (ft_count_char(info->map[0], '1') != info->map_lenght
		|| ft_count_char(info->map[info->map_height - 1], '1')
		!= info->map_lenght)
		error_message("Map is not closed with walls.", info);
	i_map = 0;
	while (i_map < info->map_height)
		if (info->map[i_map][0] != '1'
		|| info->map[i_map++][info->map_lenght - 1] != '1')
			error_message("Map is not closed with walls.", info);
}

void	check_playable(t_data *info)
{
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
				info->pos_x = i_line;
				info->pos_y = i_map;
			}
		}
	}
	info->map_copy = copy_map(info);
	visit_next_case(info->map_copy, info->pos_x, info->pos_y);
	if (char_count_sl(info->map_copy, info, 'C') != 0)
		error_message("Cannot reach all collectables.", info);
	if (char_count_sl(info->map_copy, info, 'E') != 0)
		error_message("Cannot reach exit.", info);
}

void	check_map(char	*map_name, t_data *info)
{
	check_file(map_name, info);
	create_map(info);
	check_elements(info);
	check_walls(info);
	check_playable(info);
}
