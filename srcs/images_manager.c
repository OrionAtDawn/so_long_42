/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:28:04 by edufour           #+#    #+#             */
/*   Updated: 2023/05/30 12:46:24 by edufour          ###   ########.fr       */
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
		printf("Could not correctly process asset images.\n");
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
		"./assets/collect.xpm", &info->img_x, &info->img_y);
	info->exit = mlx_xpm_file_to_image(info->mlx, \
		"./assets/exit.xpm", &info->img_x, &info->img_y);
}
