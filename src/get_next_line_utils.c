/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:25:26 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/05 15:03:39 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// len is strlen until \n is found
int	ft_strlen_gnl(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

// allocates mem for the new string (line + buffer until newline is found)
// returns everything that was read before + the last buffer until the new line
// if there is a '\n'.
char	*ft_strjoin_gnl(char *str1, char *str2)
{
	int		i;
	char	*final_str;

	i = 0;
	final_str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!final_str)
		return (NULL);
	while (str1 && str1[i])
	{
		final_str[i] = str1[i];
		i++;
	}
	free(str1);
	while (*str2)
	{
		final_str[i++] = *str2;
		if (*str2++ == '\n')
			break ;
	}
	final_str[i] = '\0';
	return (final_str);
}

//
char	ft_clean_gnl(char *buff)
{
	int	i;
	int	is_new_line;
	int	j;

	i = 0;
	j = 0;
	is_new_line = 0;
	while (buff[i])
	{
		if (is_new_line)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			is_new_line = 1;
		buff[i++] = '\0';
	}
	return (is_new_line);
}
