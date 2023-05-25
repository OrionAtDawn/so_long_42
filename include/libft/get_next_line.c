/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:30:41 by edufour           #+#    #+#             */
/*   Updated: 2023/05/12 13:24:20 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Calls read until an eol in found or read returns 0/-1.
//Puts everything in stash.
char	*read_to_stash(char *stash, int fd)
{
	char	*tmp;
	int		read_bytes;

	if (stash == NULL)
		stash = ft_calloc_gnl(BUFFER_SIZE, sizeof(char));
	if (stash == NULL)
		return (NULL);
	read_bytes = 1;
	while (ft_strchr_gnl(stash, '\n') == -1 && read_bytes > 0)
	{
		tmp = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
		if (tmp == NULL)
			return (safe_free_gnl(NULL, &stash, NULL));
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes == -1)
			return (safe_free_gnl(NULL, &stash, &tmp));
		stash = ft_strjoin_gnl(stash, tmp);
		safe_free_gnl(NULL, &tmp, NULL);
		if (stash == NULL)
			return (NULL);
	}
	return (stash);
}

//Returns a copy of everything before the first '\n' (or '\0' if not found)
char	*stash_to_line(char *stash)
{
	int		eol;
	int		i;
	char	*next_line;

	if (stash == NULL)
		return (NULL);
	eol = ft_strchr_gnl(stash, '\n');
	if (eol == -1)
		return (ft_strjoin_gnl(NULL, stash));
	next_line = ft_calloc_gnl(eol + 2, sizeof(char));
	if (next_line == NULL)
		return (NULL);
	i = -1;
	while (++i <= eol)
		next_line[i] = stash[i];
	return (next_line);
}

char	*keep_in_stash(char *stash)
{
	int		eol;
	int		i;
	char	*new_stash;

	if (stash == NULL)
		return (NULL);
	eol = ft_strchr_gnl(stash, '\n');
	if (eol == -1)
		return (safe_free_gnl(NULL, &stash, NULL));
	eol ++;
	new_stash = ft_calloc_gnl((ft_strlen_gnl(stash) - eol) + 1, sizeof(char));
	if (new_stash == NULL)
		return (safe_free_gnl(NULL, &stash, NULL));
	i = 0;
	while (stash[eol])
		new_stash[i++] = stash[eol++];
	return (safe_free_gnl(new_stash, &stash, NULL));
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(stash, fd);
	if (stash == NULL)
		return (NULL);
	if (stash[0] == 0)
		return (safe_free_gnl(NULL, &stash, NULL));
	next_line = stash_to_line(stash);
	stash = keep_in_stash(stash);
	return (next_line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int	fd;
// 	char	*line;
// 	fd = open("/Users/edufour/Desktop/gnl_elo/text.txt", O_RDONLY);
// 	// printf("%d", fd);

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	// while (line != NULL)
// 	// {
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// 	line = get_next_line(fd);
// 	// }
// 	if (line)
// 		free (line);
// }
