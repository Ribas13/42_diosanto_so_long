/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:10:20 by diosanto          #+#    #+#             */
/*   Updated: 2023/09/20 12:20:39 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>
#include <stdio.h>

static void	av_checker(int ac, char **av)
{
	if (ac != 2)
		errors(NULL, INVALID_NBR_ARGS);
	if (*av[1] == '\0')
		errors(NULL, NULL_MAP);
}

int	main(int ac, char **av)
{
	t_game	game;

	av_checker(ac, av);
	game = init_game();
	get_map(av[1], &game);
	map_check(&game);
	init_mlx(&game);
	render_map(&game);
	hook_n_run(&game);
	return (EXIT_SUCCESS);
}
