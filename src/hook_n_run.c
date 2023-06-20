/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_n_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:02:21 by ribs              #+#    #+#             */
/*   Updated: 2023/06/20 15:08:56 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	quit_game(t_game *game)
{
	destroy(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_press(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
	else if (key == W || key == UP)
		update_player_pos(game, false, -1);
	else if (key == A || key == LEFT)
		update_player_pos(game, true, -1);
	else if (key == S || key == DOWN)
		update_player_pos(game, false, 1);
	else if (key == D || key == RIGHT)
		update_player_pos(game, true, 1);
	return (EXIT_SUCCESS);
}

void	hook_n_run(t_game *game)
{
	mlx_hook(game->win_ptr, KEYPRESS_EVENT, (1L << 0), on_press, game);
	mlx_hook(game->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), quit_game, game);
	mlx_loop(game->mlx_ptr);
}
