/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:28:04 by edufour           #+#    #+#             */
/*   Updated: 2023/05/26 15:34:51 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images(t_data *info)
{
	info->ghost = mlx_xpm_file_to_image(info->mlx, \
		"./sprites/character.xpm", &info->img_x, &info->img_y);
}
