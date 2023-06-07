/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:21:30 by edufour           #+#    #+#             */
/*   Updated: 2023/06/07 11:50:03 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "libft/libft.h"

//pos_x and 

typedef struct s_data
{
	char	**map;
	char	**map_copy;
	char	*path;
	int		fd;
	int		map_height;
	int		map_lenght;
	int		collectables;
	int		moves;
	char	exit_flag;

	int		pos_x;
	int		pos_y;

	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_x;
	int		img_y;

	void	*ghost_right;
	void	*ghost_left;
	void	*ghost_front;
	void	*ghost_back;
	void	*ghost;
	void	*floor;
	void	*wall;
	void	*collect;
	void	*exit_hold;
	void	*exit;	
}	t_data;

//Parsing
void	error_message(char *error, t_data *info);
void	check_elements(t_data *info);
void	check_walls(t_data *info);
void	check_playable(t_data *info);
void	check_file(char *map_name, t_data *info);
void	check_map(char	*map_name, t_data *info);

void	create_map(t_data *info);

int		count_nb_lines(t_data *info);
int		char_count_sl(char **map, t_data *info, char find);
int		compare_lenght(t_data *info);
void	visit_next_case(char **map, int y, int x);
char	**copy_map(t_data *info);
void	move_on_screen(t_data *info);
//mlx
void	window_init(t_data *info);
int		keybinds(int keycode, t_data *info);
int		exit_window(t_data *info);
void	get_images(t_data *info);
void	check_img(void);
void	put_images(t_data *info);
void	go_right(t_data *info);
void	go_left(t_data *info);
void	go_up(t_data *info);
void	go_down(t_data *info);

void	exit_free(t_data *info);

#endif