/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:04:35 by marvin            #+#    #+#             */
/*   Updated: 2024/07/27 00:04:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_tab_int(int **tab)
{
	int (i) = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
}

void	free_all(t_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	ft_free_tab(data->map);
	ft_free_tab_int(data->texture_buffer);
	free(data->rays);
	free(data->map);
	free(data->mlx_ptr);
	exit(0);
}

void	render_frame(t_data *data)
{
	int (x) = 0;
	while (x < WIN_WIDTH)
	{
		cast_rays(data, x);
		draw_game(data, x);
		x++;
	}
}

int	render_loop(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	render_frame(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

int	main(void)
{
	t_data		data;

	init_mlx(&data);
	init_map(&data);
	init_player(&data);
	init_textures(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, render_loop, &data);
	mlx_loop(data.mlx_ptr);
	free_all(&data);
}
