/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:12:41 by ribs              #+#    #+#             */
/*   Updated: 2023/06/18 18:44:55 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		errors(game, MLX_INIT_ERR);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map.columns * TILE_SIZE, game->map.rows * TILE_SIZE,
			"so_long");
	if (!game->win_ptr)
		errors(game, MLX_NEW_WINDOW_ERR);
}
