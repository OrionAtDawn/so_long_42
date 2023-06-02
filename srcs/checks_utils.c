/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:22:03 by edufour           #+#    #+#             */
/*   Updated: 2023/06/02 11:16:24 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_nb_lines(t_data *info)
{
	char	*line;

	info->map_height = 0;
	line = get_next_line(info->fd);
	if (line == NULL)
		return (1);
	if (line[0] == 0)
		return (1);
	while (line != NULL)
	{
		if (line[0] != '\n')
			info->map_height++;
		free (line);
		line = get_next_line(info->fd);
	}
	safe_free(0, (void **)line);
	close (info->fd);
	return (0);
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

int	char_count_sl(char **map, t_data *info, char find)
{
	int	i_map;
	int	i_line;
	int	count;

	i_map = 0;
	count = 0;
	while (i_map < info->map_height)
	{	
		i_line = 0;
		while (i_line < info->map_lenght)
		{	
			if (map[i_map][i_line] == find)
				count ++;
			i_line++;
		}
		i_map++;
	}
	return (count);
}

void	error_message(char *error, t_data *info)
{
	printf("Error\n%s\n", error);
	exit_free(NULL, info);
}

int	compare_lenght(t_data *info)
{
	int	i_map;
	int	lenght;

	i_map = 1;
	while (i_map < info->map_height - 1)
	{
		lenght = (int)ft_strlen(info->map[i_map]) - 1;
		if (info->map_lenght != lenght)
			return (1);
		i_map++;
	}
	if (info->map_lenght != (int)ft_strlen(info->map[info->map_height - 1]))
		return (1);
	return (0);
}
