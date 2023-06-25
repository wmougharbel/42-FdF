/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:30:56 by wmoughar          #+#    #+#             */
/*   Updated: 2023/06/05 16:25:21 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>

void	settings(t_fdf *data, int window_x, int window_y, float zoom)
{
	data->window_x = window_x;
	data->window_y = window_y;
	data->zoom = zoom;
	if (data->map_size <= 500)
		data->depth = 2.5;
	else if (data->map_size <= 3000)
		data->depth = 4;
	else if (data->map_size <= 5000)
		data->depth = 7;
	else if (data->map_size <= 10000)
		data->depth = 6;
	else
		data->depth = 0.2;
	data->projection = 1;
}

void	defaults(t_fdf *data, char **av)
{
	read_map(data, av[1]);
	if (data->map_size <= 500)
		settings(data, 920, 680, 20);
	else if (data->map_size <= 3000)
		settings(data, 1280, 720, 15);
	else if (data->map_size <= 5000)
		settings(data, 1366, 768, 15);
	else if (data->map_size <= 10000)
		settings(data, 1600, 900, 12);
	else
		settings(data, 1920, 1080, 5);
	ft_printf("Generating Map...\n");
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac == 2 && ft_error(2, ac, av[1]))
	{
		data = malloc(sizeof(t_fdf));
		data->l = malloc(sizeof(t_line));
		data->mlx_img = malloc(sizeof(t_data));
		defaults(data, av);
		data->mlx_ptr = mlx_init();
		data->mlx_window = mlx_new_window(data->mlx_ptr, data->window_x,
				data->window_y, "FDF");
		mlx_image(data, 0, 0);
		mlx_mouse_hook(data->mlx_window, mouse_controls, data);
		mlx_hook(data->mlx_window, 2, 0, key_controls, data);
		mlx_hook(data->mlx_window, 17, 0, ft_close, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_error(1, ac, "none");
}
