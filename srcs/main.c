/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:21:54 by edufour           #+#    #+#             */
/*   Updated: 2023/05/26 15:27:27 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	variables_init(t_data *info)
{
	info->collectables = 0;
	info->fd = 0;
	info->map_height = 0;
	info->map_lenght = 0;
	info->position_x = 0;
	info->position_y = 0;	
}

int	main(int argc, char **argv)
{
	t_data	info;

	variables_init(&info);
	if (argc != 2)
		return (error_message("No file was provided."));
	info.path = argv[1];
	if (check_map(argv[1], &info) == -1)
		return (1);
	window_init(&info);
	mlx_key_hook(info.mlx_win, keybinds, &info);
	mlx_hook(info.mlx_win, 17, 0, exit_window, &info);
	mlx_loop(info.mlx);
	get_images(&info);
}
