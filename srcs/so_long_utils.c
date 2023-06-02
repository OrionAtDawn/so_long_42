/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:16:51 by edufour           #+#    #+#             */
/*   Updated: 2023/06/02 13:30:51 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_ptr(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (0);
}

void	*free_tab(char ***ptab)
{
	char	**tab;

	if (!ptab || !(*ptab))
		return (NULL);
	tab = *ptab;
	while (*(tab))
	{
		free_ptr((void **)tab);
		tab++;
	}
	free_ptr((void **)ptab);
	return (NULL);
}

void	exit_free(t_data *info)
{
	if (info->map != NULL)
		free_tab(&info->map);
	if (info->map_copy != NULL)
		free_tab(&info->map_copy);
	exit (0);
}

void	create_map(t_data *info)
{
	int	i_map;

	if (count_nb_lines(info) != 0 || \
		info->map_height < 3 || info->map_height > 30)
		error_message("Map format invalid.", info);
	info->map = ft_calloc(info->map_height + 1, sizeof(char *));
	i_map = 0;
	open(info->path, O_RDONLY);
	while (i_map < info->map_height)
		info->map[i_map++] = get_next_line(info->fd);
	info->map[i_map] = NULL;
	info->map_lenght = ft_strlen(info->map[0]) - 1;
	if (info->map_lenght < 3 || info->map_lenght > 40)
		error_message("Map format invalid.", info);
}

char	**copy_map(t_data *info)
{
	char **new_map;
	int	i;

	new_map = ft_calloc(info->map_height + 1, sizeof(char *));
	i = -1;
	while (++i < info->map_height)
		new_map[i] = ft_strdup(info->map[i]);
	new_map[i] = NULL;
	return (new_map);
}