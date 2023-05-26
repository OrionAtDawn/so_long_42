/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:18:01 by edufour           #+#    #+#             */
/*   Updated: 2023/05/26 15:32:26 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void window_init(t_data *info)
{
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, info->map_lenght * 64, 
		info->map_height * 64, "so_long");
}

int	keybinds(int keycode, t_data *info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->mlx_win);
		exit(0);
	}
	return (0);
}

int	exit_window(t_data *info)
{
	mlx_destroy_window(info->mlx, info->mlx_win);
	exit(0);
	return(0);
}

void	get_images(t_data *info)
{
	info->ghost = mlx_xpm_file_to_image(info->mlx, \
		"./sprites/character.xpm", &info->img_x, &info->img_y);
}
