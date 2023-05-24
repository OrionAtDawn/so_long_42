/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:04:55 by edufour           #+#    #+#             */
/*   Updated: 2023/05/12 13:20:28 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> 
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strjoin_gnl(char *base, char *add);
void	*ft_calloc_gnl(size_t nb, size_t size);
int		ft_strchr_gnl(char *str, char search);
int		ft_strlen_gnl(const char *s);
char	*read_to_stash(char *stash, int fd);
char	*stash_to_line(char *stash);
char	*keep_in_stash(char *stash);
char	*get_next_line(int fd);
char	*safe_free_gnl(char *return_value, char **to_free, char **to_free_too);

#endif