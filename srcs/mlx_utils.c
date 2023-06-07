/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:18:01 by edufour           #+#    #+#             */
/*   Updated: 2023/06/07 11:49:16 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_on_screen(t_data *info)
{
	char	*nbmv;

	nbmv = ft_itoa(info->moves);
	mlx_string_put(info->mlx, info->mlx_win, 62, 60, 0x000000FF, "Moves: ");
	mlx_string_put(info->mlx, info->mlx_win, 125, 60, 0x000000FF, nbmv);
	free(nbmv);
}

void	window_init(t_data *info)
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
		exit_free(info);
	}
	if (keycode == 0 || keycode == 123)
	{
		go_left(info);
	}
	if (keycode == 2 || keycode == 124)
	{
		go_right(info);
	}
	if (keycode == 1 || keycode == 125)
	{
		go_down(info);
	}
	if (keycode == 13 || keycode == 126)
	{
		go_up(info);
	}
	return (0);
}

int	exit_window(t_data *info)
{
	mlx_destroy_window(info->mlx, info->mlx_win);
	return (exit_free(info), 0);
}
