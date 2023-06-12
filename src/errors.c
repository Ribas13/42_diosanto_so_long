/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:03:46 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/12 11:17:39 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	is_onstr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] == ch)
			return (true);
		i += 1;
	}
	return (false);
}

void	errors(t_game *game, char *error_msg)
{
	destroy(game);
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
