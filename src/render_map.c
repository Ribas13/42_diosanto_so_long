/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:17:55 by ribs              #+#    #+#             */
/*   Updated: 2023/06/18 18:47:26 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_error_on_xpms(t_game *game)
{	
	if (!game->tiles.wall)
		errors(game, WALL_XPM_ERR);
	if (!game->tiles.floor)
		errors(game, PLAYER_XPM_ERR);
	if (!game->tiles.player)
		errors(game, PLAYER_XPM_ERR);
	if (!game->tiles.collectible)
		errors(game, COLLECTIBLE_XPM_ERR);
	if (!game->tiles.exit)
		errors(game, EXIT_XPM_ERR);
}

static void	open_xpm(t_game *game)
{
	int	img_size;

	img_size = TILE_SIZE;
	game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL_TILE, &img_size, &img_size);
	game->tiles.floor = mlx_xpm_file_to_image(game->mlx_ptr,
			FLOOR_TILE, &img_size, &img_size);
	game->tiles.player = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_TILE, &img_size, &img_size);
	game->tiles.collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE_TILE, &img_size, &img_size);
	game->tiles.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_TILE, &img_size, &img_size);
	check_error_on_xpms(game);
}

void	render_tiles(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (game->map.map[i][j] == WALL)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.wall, TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map.map[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.collectible, TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map.map[i][j] == EXIT)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.exit, TILE_SIZE * j, TILE_SIZE * i);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.floor, TILE_SIZE * j, TILE_SIZE * i);
		}
	}
	put_player_tile(game);
}

void	render_map(t_game *game)
{
	open_xpm(game);
	render_tiles(game);
}
