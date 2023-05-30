/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:21:30 by edufour           #+#    #+#             */
/*   Updated: 2023/05/30 12:41:00 by edufour          ###   ########.fr       */
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
	//map info
	char	**map;
	char	*path;
	int		fd;
	int		map_height;
	int		map_lenght;
	int		collectables;
	//player position
	int		position_x;
	int		position_y;
	//mlx
	void	*mlx;
	void	*mlx_win;
	void	*img;
	//images pointers
	void	*ghost;
	void	*ghost_left;
	void	*ghost_front;
	void	*ghost_back;
	void	*floor;
	void	*wall;
	void	*collect;
	void	*exit;
	int		img_x;
	int		img_y;
}	t_data;

//Parsing
int		error_message(char *error);
int		check_elements(t_data *info);
int		check_walls(t_data *info);
int		check_playable(t_data *info);
int		check_file(char *map_name, t_data *info);
int		check_map(char	*map_name, t_data *info);

int		create_map(t_data *info);

void	count_nb_lines(t_data *info);
int		char_count_sl(t_data *info, char find);
int		compare_lenght(t_data *info);
void	visit_next_case(char **map, int y, int x);
char	**copy_map(t_data *info);
//mlx
void	window_init(t_data *info);
int		keybinds(int keycode, t_data *info);
int		exit_window(t_data *info);
void	get_images(t_data *info);
void	check_img(void);

#endif