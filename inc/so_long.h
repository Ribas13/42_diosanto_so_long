/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:05:52 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/05 18:49:23 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	//char	**map;
	void	*img_backg;
	//void	*img_wall;
	//void	*img_player;
	//void	*img_colect;
	//void	*img_exit;
	//int		map_w;
	//int		map_h;
	int		img_w;
	int		img_h;
	//int		n_colect;
	//int		n_player;
	//int		n_exit;
	//int		x_player;
	//int		y_player;
	//int		moves;
	//int		endgame;
}		t_game;

# define BUFFER_SIZE 5

//Function Prototypes

//GNL
int				ft_strlen_gnl(char *str);
char			*ft_strjoin_gnl(char *str1, char *str2);
char			ft_clean_gnl(char *buff);
char			*get_next_line(int fd);

//so_long functions
void			game_init(t_game *game);
static void		image_init(t_game *game);

#endif