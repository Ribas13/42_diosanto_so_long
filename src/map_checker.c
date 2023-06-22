/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:34:07 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/22 15:44:09 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#define VALID_ENTITIES "ECP01"

static void	throw_error_if(t_game *game)
{
	if (game->map.exit == 0 || game->map.exit > 1)
		errors(game, INVALID_NBR_EXITS);
	if (game->map.collectibles == 0)
		errors(game, NO_COLLECTIBLES);
	if (game->map.player == 0 || game->map.player > 1)
		errors(game, INVALID_NBR_PLAYERS);
}

static void	check_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (!is_onstr(VALID_ENTITIES, game->map.map[i][j]))
				errors(game, INVALID_ENTITY);
			if (game->map.map[i][j] == EXIT)
				game->map.exit += 1;
			else if (game->map.map[i][j] == COLLECTIBLE)
				game->map.collectibles += 1;
			else if (game->map.map[i][j] == PLAYER)
			{
				game->map.player += 1;
				game->map.player_pos = (t_point){j, i};
			}
		}
	}
	throw_error_if(game);
}

static bool	is_closed(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->rows)
		if (map->map[i][0] != WALL || map->map[i][map->columns - 1] != WALL)
			return (false);
	i = -1;
	while (++i < map->columns)
		if (map->map[0][i] != WALL || map->map[map->rows - 1][i] != WALL)
			return (false);
	return (true);
}

static bool	valid_form(t_game *game)
{
	size_t	len;
	size_t	i;

	len = game->map.columns;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		// printf("Number of rows: %zu\n", ft_strlen(game->map.map[i]));
		if (len != ft_strlen(game->map.map[i]))
			return (false);
		i += 1;
	}
	return (true);
}

void	map_check(t_game *game)
{
	if (!valid_form(game))
		errors(game, INVALID_FORMAT);
	check_elements(game);
	if (!is_closed(&game->map))
		errors(game, MAP_NOT_CLOSED);
	check_path(game);
}
