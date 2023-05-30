/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:18:01 by edufour           #+#    #+#             */
/*   Updated: 2023/05/30 12:39:27 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void window_init(t_data *info)
{
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, info->map_lenght * 64, 
		info->map_height * 64, "./so_long");
}

int	keybinds(int keycode, t_data *info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->mlx_win);
		exit(0);
	}
	// if (keycode == 0 || keycode == 123)
	// {
	// 	go_left;
	// }
	// if (keycode == 2 || keycode == 124)
	// {
	// 	go_right;
	// }
	// if (keycode == 1 || keycode == 125)
	// {
	// 	go_down;
	// }
	// if (keycode == 13 || keycode == 126)
	// {
	// 	go_up;
	// }
	return (0);
}

int	exit_window(t_data *info)
{
	mlx_destroy_window(info->mlx, info->mlx_win);
	exit(0);
	return(0);
}
