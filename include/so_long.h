/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:21:30 by edufour           #+#    #+#             */
/*   Updated: 2023/05/25 09:20:24 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h> 
// # include <mlx.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

//pos_x and 

typedef struct s_data
{
	char	**map;
	char	*path;
	int		fd;
	int		collectables;
	int		position_x;
	int		position_y;
	int		map_height;
	int		map_lenght;
}	t_data;

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

#endif