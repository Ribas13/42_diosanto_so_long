/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:25:32 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/05 15:04:59 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (buff[i])
			buff[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin_gnl(line, buff);
		if (ft_clean_gnl(buff))
			break ;
	}
	return (line);
}
