/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:05:52 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/13 18:04:39 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"
# include "error_messages.h"

//Constants

# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

# define KEYPRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17

# define WIN_MSG "You won!\n"

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		collectibles;
	int		exit;
	int		player;
	t_point	player_pos;
}			t_map;

typedef struct s_tiles
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}			t_tiles;

typedef struct s_game
{
	t_map	map;
	void	*mlx_ptr;
	void	*win_ptr;
	t_tiles	tiles;
	int		moves;
}			t_game;

static inline	t_game	init_game(void)
{
	return ((t_game){
		.map.map = NULL,
		.map.rows = 0,
		.map.columns = 0,
		.map.collectibles = 0,
		.map.exit = 0,
		.map.player = 0,
		.tiles.collectible = NULL,
		.tiles.exit = NULL,
		.tiles.floor = NULL,
		.tiles.player = NULL,
		.tiles.wall = NULL,
		.moves = -1,
	});
}

//Function Prototypes

//GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif 

bool		is_onstr(const char *str, int ch);
char		*get_next_line(int fd);

//so_long functions


//Map Functions
void		get_map(char *map_file, t_game *game);
void		map_check(t_game *game);
void		check_path(t_game *game);
char		*trim_free(char *s1, char const *set);

//Error handling
void		errors(t_game *game, char *error_msg);

//Destroy functions
void		free_matrix(char **matrix);
void		destroy_tiles(t_game *game);
void		destroy(t_game *game);

#endif