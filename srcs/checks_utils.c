/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:22:03 by edufour           #+#    #+#             */
/*   Updated: 2023/05/31 16:06:25 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_nb_lines(t_data *info)
{
	char	*line;

	info->map_height = 0;
	line = get_next_line(info->fd);
	if (line == NULL)
		return;
	while (line != NULL)
	{
		if (line[0] != '\n')
			info->map_height++;
		free (line);
		line = get_next_line(info->fd);
	}
	safe_free(0, (void **)line);
	close (info->fd);
}

int	create_map(t_data *info)
{
	int	i_map;

	count_nb_lines(info);
	if (info->map_height < 3 || info->map_height > 30)
		return (error_message("Map format invalid.", info));
	info->map = ft_calloc(info->map_height, sizeof(char *));
	i_map = 0;
	open(info->path, O_RDONLY);
	while (i_map < info->map_height)
		info->map[i_map++] = get_next_line(info->fd);
	info->map_lenght = ft_strlen(info->map[0]) - 1;
	if (info->map_lenght < 3 || info->map_lenght > 40)
		return (error_message("Map format invalid.", info));
	return (0);
}

int	char_count_sl(t_data *info, char find)
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
			if (info->map[i_map][i_line] == find)
				count ++;
			i_line++;
		}
		i_map++;
	}
	return (count);
}

int	error_message(char *error, t_data *info)
{
	exit_free(info);
	printf("Error\n%s\n", error);
	return (1);
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
