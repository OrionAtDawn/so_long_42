/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:21:54 by edufour           #+#    #+#             */
/*   Updated: 2023/05/25 09:23:05 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	info;

	if (argc != 2)
		return (error_message("No file was provided."));
	info.path = argv[1];
	if (check_map(argv[1], &info) == -1)
		return (1);
}
