/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:10:20 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/05 18:04:45 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>
#include <stdio.h>

static void	image_init(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image(game->mlx, "../img/600x300.xpm",
			&game->img_w, &game->img_h);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->map_w = 600;
	game->map_h = 300;
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h,
			"SHIT SHOW!!");
	image_init(game);
}

int	main(void)
{
	t_game	*game;

	game_init(game);
}
