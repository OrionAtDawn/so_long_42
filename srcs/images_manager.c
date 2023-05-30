/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:28:04 by edufour           #+#    #+#             */
/*   Updated: 2023/05/30 15:18:34 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	valid_fd(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		return (1);
	}
	close (fd);
	return (0);
}

void	check_img(void)
{
	if (valid_fd("./assets/character.xpm") == 1
		|| valid_fd("./assets/character_left.xpm") == 1
		|| valid_fd("./assets/character_front.xpm") == 1
		|| valid_fd("./assets/character_back.xpm") == 1
		|| valid_fd("./assets/floor.xpm") == 1
		|| valid_fd("./assets/wall.xpm") == 1
		|| valid_fd("./assets/collectable.xpm") == 1
		|| valid_fd("./assets/exit.xpm") == 1)
	{
		printf("An error with the textures file(s) occured.\n");
		exit (0);
	}
}

void	get_images(t_data *info)
{
	info->ghost = mlx_xpm_file_to_image(info->mlx, \
		"./assets/character.xpm", &info->img_x, &info->img_y);
	info->ghost_left = mlx_xpm_file_to_image(info->mlx, \
		"./assets/character_left.xpm", &info->img_x, &info->img_y);
	info->ghost_front = mlx_xpm_file_to_image(info->mlx, \
		"./assets/character_front.xpm", &info->img_x, &info->img_y);
	info->ghost_back = mlx_xpm_file_to_image(info->mlx, \
		"./assets/character_back.xpm", &info->img_x, &info->img_y);
	info->floor = mlx_xpm_file_to_image(info->mlx, \
		"./assets/floor.xpm", &info->img_x, &info->img_y);
	info->wall = mlx_xpm_file_to_image(info->mlx, \
		"./assets/wall.xpm", &info->img_x, &info->img_y);
	info->collect = mlx_xpm_file_to_image(info->mlx, \
		"./assets/collectable.xpm", &info->img_x, &info->img_y);
	info->exit = mlx_xpm_file_to_image(info->mlx, \
		"./assets/exit.xpm", &info->img_x, &info->img_y);
	put_images(info);
}

void	put_images(t_data *info)
{
	int	i_map;
	int	i_line;

	i_map = 0;
	while(i_map < info->map_height)
	{	
		i_line = 0;
		while (i_line < info->map_lenght)
		{	
			if(info->map[i_map][i_line] == 'P')
				mlx_put_image_to_window(info->mlx, info->mlx_win, \
					info->ghost, i_line*64, i_map*64);
			else if(info->map[i_map][i_line] == '0')
				mlx_put_image_to_window(info->mlx, info->mlx_win, \
					info->floor, i_line*64, i_map*64);
			else if(info->map[i_map][i_line] == '1')
				mlx_put_image_to_window(info->mlx, info->mlx_win, \
					info->wall, i_line*64, i_map*64);
			else if(info->map[i_map][i_line] == 'C')
				mlx_put_image_to_window(info->mlx, info->mlx_win, \
					info->collect, i_line*64, i_map*64);
			else if(info->map[i_map][i_line] == 'E')
				mlx_put_image_to_window(info->mlx, info->mlx_win, \
					info->exit, i_line*64, i_map*64);
			i_line++;
		}
		i_map++;
	}
		
}