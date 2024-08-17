/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:04:54 by marvin            #+#    #+#             */
/*   Updated: 2024/07/27 00:04:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05
# define TEXTURE_SIZE 64
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

typedef struct s_raycasting
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
}	t_raycasting;

typedef struct s_player
{
	double			player_x;
	double			player_y;
	double			player_dir_x;
	double			player_dir_y;
	double			plane_x;
	double			plane_y;
}	t_player;

typedef struct s_textures
{
	int		*image_texture_data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	int		y;
	int		tex_x;
	double	pos;
	double	step;
	double	wall_x;
	int		draw_start;
	int		draw_end;

}	t_textures;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_data;
	char			**map;
	int				bpp;
	int				ceiling_color;
	int				floor_color;
	int				endian;
	int				size_line;
	int				*texture_buffer[4];
	t_raycasting	*rays;
	t_player		player;
	t_textures		texture;
}	t_data;

//fonctions
void	init_map(t_data *data);
void	init_mlx(t_data *data);
void	init_player(t_data *data);
int		handle_keypress(int keycode, t_data *data);
void	draw_game(t_data *data, int x);
void	cast_rays(t_data *data, int x);
void	init_textures(t_data *data);
void	free_all(t_data *data);

#endif