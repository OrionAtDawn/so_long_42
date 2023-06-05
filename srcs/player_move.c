/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:17:01 by edufour           #+#    #+#             */
/*   Updated: 2023/06/05 11:14:25 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	go_right(t_data *info)
{
	if (info->map[info->pos_y][info->pos_x + 1] != '1')
	{	
		if (info->collectables == 0)
			info->exit = info->exit_hold;
		if (info->map[info->pos_y][info->pos_x + 1] == 'C')
			info->collectables--;
		if (info->map[info->pos_y][info->pos_x + 1] == 'E')
		{	
			if (info->collectables == 0)
			{
				info->moves++;
				printf("Moves : %d\n", info->moves);
				exit_free(info);
			}
		}
		info->ghost = info->ghost_right;
		info->map[info->pos_y][info->pos_x] = info->exit_flag;
		if (info->exit_flag == 'E')
			info->exit_flag = '0';
		if (info->map[info->pos_y][info->pos_x + 1] == 'E')
			info->exit_flag = 'E';
		info->map[info->pos_y][info->pos_x + 1] = 'P';
		info->pos_x += 1;
		info->moves++;
		printf("Moves : %d\n", info->moves);
		put_images(info);
	}
}

void	go_left(t_data *info)
{
	if (info->collectables == 0)
			info->exit = info->exit_hold;
	if (info->map[info->pos_y][info->pos_x - 1] != '1')
	{	
		if (info->map[info->pos_y][info->pos_x - 1] == 'C')
			info->collectables--;
		if (info->map[info->pos_y][info->pos_x - 1] == 'E')
		{	
			if (info->collectables == 0)
			{
				info->moves++;
				printf("Moves : %d\n", info->moves);
				exit_free(info);
			}
		}
		info->ghost = info->ghost_left;
		info->map[info->pos_y][info->pos_x] = info->exit_flag;
		if (info->exit_flag == 'E')
			info->exit_flag = '0';
		if (info->map[info->pos_y][info->pos_x - 1] == 'E')
			info->exit_flag = 'E';
		info->map[info->pos_y][info->pos_x - 1] = 'P';
		info->pos_x -= 1;
		info->moves++;
		printf("Moves : %d\n", info->moves);
		put_images(info);
	}
}

void	go_down(t_data *info)
{
	if (info->collectables == 0)
			info->exit = info->exit_hold;
	if (info->map[info->pos_y + 1][info->pos_x] != '1')
	{	
		if (info->map[info->pos_y + 1][info->pos_x] == 'C')
			info->collectables--;
		if (info->map[info->pos_y + 1][info->pos_x] == 'E')
		{	
			if (info->collectables == 0)
			{
				info->moves++;
				printf("Moves : %d\n", info->moves);
				exit_free(info);
			}
		}
		info->ghost = info->ghost_front;
		info->map[info->pos_y][info->pos_x] = info->exit_flag;
		if (info->exit_flag == 'E')
			info->exit_flag = '0';
		if (info->map[info->pos_y + 1][info->pos_x] == 'E')
			info->exit_flag = 'E';
		info->map[info->pos_y + 1][info->pos_x] = 'P';
		info->pos_y += 1;
		info->moves++;
		printf("Moves : %d\n", info->moves);
		put_images(info);
	}
}

void	go_up(t_data *info)
{
	if (info->collectables == 0)
			info->exit = info->exit_hold;
	if (info->map[info->pos_y - 1][info->pos_x] != '1')
	{	
		if (info->map[info->pos_y - 1][info->pos_x] == 'C')
			info->collectables--;
		if (info->map[info->pos_y - 1][info->pos_x] == 'E')
		{	
			if (info->collectables == 0)
			{
				info->moves++;
				printf("Moves : %d\n", info->moves);
				exit_free(info);
			}
		}
		info->ghost = info->ghost_back;
		info->map[info->pos_y][info->pos_x] = info->exit_flag;
		if (info->exit_flag == 'E')
			info->exit_flag = '0';
		if (info->map[info->pos_y - 1][info->pos_x] == 'E')
			info->exit_flag = 'E';
		info->map[info->pos_y - 1][info->pos_x] = 'P';
		info->pos_y -= 1;
		info->moves++;
		printf("Moves : %d\n", info->moves);
		put_images(info);
	}
}