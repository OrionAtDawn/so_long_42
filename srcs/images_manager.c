/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:28:04 by edufour           #+#    #+#             */
/*   Updated: 2023/05/27 18:14:55 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_images(t_data *info)
{
	info->ghost = mlx_xpm_file_to_image(info->mlx, \
		"./sprites/character.xpm", &info->img_x, &info->img_y);
	info->floor = mlx_xpm_file_to_image(info->mlx, \
		"./sprites/floor.xpm", &info->img_x, &info->img_y);
	info->wall = mlx_xpm_file_to_image(info->mlx, \
		"./sprites/wall.xpm", &info->img_x, &info->img_y);
	info->collect = mlx_xpm_file_to_image(info->mlx, \
		"./sprites/collect.xpm", &info->img_x, &info->img_y);
	info->exit = mlx_xpm_file_to_image(info->mlx, \
		"./sprites/exit.xpm", &info->img_x, &info->img_y);
}
