/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:10:20 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/06 13:17:13 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>
#include <stdio.h>

//https://github.com/igorvazf/so_long

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 32, y * 32);
}

int	map_draw(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (x == 0 && y == 0)
		img_draw(game, game->img_backg, x, y);
	if (x == 0 && y == 0)
		return (0);
	return (0);
}

void	image_init(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image(game->mlx, "../img/600x300.xpm",
			&game->img_w, &game->img_h);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 600, 300,
			"SHIT SHOW!!");
	mlx_loop(game->mlx);
	image_init(game);
	map_draw(game);
}

t_game	*ft_game(void)
{
	static t_game	game;

	return (&game);
}

int	main(void)
{
	t_game	*game;

	game = ft_game();
	game_init(game);
}
