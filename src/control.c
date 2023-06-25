/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:34:12 by wmoughar          #+#    #+#             */
/*   Updated: 2023/06/05 16:39:06 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(t_fdf *data)
{
	free_everything(data);
	exit(1);
}

int	mouse_controls(int key, int x, int y, t_fdf *data)
{
	static int	tmp;
	static int	flag;

	if (key == 1 || key == 4 || key == 5)
	{
		if (key == 4)
			data->zoom += 1;
		else if (key == 5)
			data->zoom -= 1;
		else if (key == 1 && flag == 0)
		{
			flag = 1;
			tmp = data->zoom;
			data->zoom = tmp - 1;
			data->projection = 0;
		}
		else if (key == 1 && flag == 1)
		{
			flag = 0;
			data->zoom = tmp;
			data->projection = 1;
		}
		mlx_image(data, x, y);
	}
	return (0);
}

int	key_controls(int key, t_fdf *data)
{
	if (key == 13 || key == 0 || key == 1
		|| key == 2 || key == 53 || key == 125 || key == 126)
	{
		if (key == 2)
			data->position_x += 50;
		else if (key == 0)
			data->position_x -= 50;
		else if (key == 13)
			data->position_y -= 50;
		else if (key == 1)
			data->position_y += 50;
		else if (key == 126)
			data->depth += 0.1;
		else if (key == 125)
			data->depth -= 0.1;
		else if (key == 53)
		{
			mlx_destroy_image(data->mlx_ptr, data->mlx_img->img);
			mlx_destroy_window(data->mlx_ptr, data->mlx_window);
			free_everything(data);
			exit(1);
		}
		mlx_image(data, 1, 1);
	}
	return (0);
}
