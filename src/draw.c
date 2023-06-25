/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:10:47 by wmoughar          #+#    #+#             */
/*   Updated: 2023/06/03 20:26:13 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx_img->addr + (y * data->mlx_img->line_length + x
			* (data->mlx_img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_fdf *data, float x_steps, float y_steps)
{
	if ((0 <= data->l->x_s && data->l->x_s <= data->window_x)
		&& (0 <= data->l->y_s && data->l->y_s <= data->window_y))
	{
		while (((int)(data->l->x_e - data->l->x_s) || (int)(data->l->y_e
			- data->l->y_s)) && ((0 <= data->l->x_s
					&& data->l->x_s <= data->window_x) && (0 <= data->l->y_s
					&& data->l->y_s <= data->window_y)))
		{
			color_pixel_put(data, data->l->x_s, data->l->y_s, data->color);
			data->l->x_s += x_steps;
			data->l->y_s += y_steps;
		}
	}
}

void	position_zoom(t_fdf *data, float x_e, float y_e)
{
	data->l->x_s = data->l->l_x_s * data->zoom;
	data->l->x_e = x_e * data->zoom;
	data->l->y_s = data->l->l_y_s * data->zoom;
	data->l->y_e = y_e * data->zoom;
	data->l->x_s += data->position_x + 500;
	data->l->x_e += data->position_x + 500;
	data->l->y_s += data->position_y - 75;
	data->l->y_e += data->position_y - 75;
}

void	ft_dda(t_fdf *data, float x_e, float y_e)
{
	float	x_step;
	float	y_step;

	data->l->z_s = data->z_matrix[(int)data->l->l_y_s][(int)data->l->l_x_s];
	data->l->z_e = data->z_matrix[(int)y_e][(int)x_e];
	color(data, x_e, y_e);
	position_zoom(data, x_e, y_e);
	if (data->projection)
	{
		data->l->x_s = (data->l->x_s - data->l->y_s) * 0.5;
		data->l->y_s = (data->l->x_s + data->l->y_s) * 0.5 - (data->l->z_s
				* data->depth);
		data->l->x_e = (data->l->x_e - data->l->y_e) * 0.5;
		data->l->y_e = (data->l->x_e + data->l->y_e) * 0.5 - (data->l->z_e
				* data->depth);
	}
	x_step = data->l->x_e - data->l->x_s;
	y_step = data->l->y_e - data->l->y_s;
	x_step /= s(p(data->l->x_e - data->l->x_s), p(data->l->y_e - data->l->y_s));
	y_step /= s(p(data->l->x_e - data->l->x_s), p(data->l->y_e - data->l->y_s));
	draw(data, x_step, y_step);
}

void	illustrate(t_fdf *data)
{
	float	x;
	float	y;

	y = 0;
	data->l->l_y_s = 0;
	while (data->height > data->l->l_y_s)
	{
		data->l->l_x_s = 0;
		x = 0;
		while (data->width > data->l->l_x_s)
		{
			if (data->width - 1 > data->l->l_x_s)
				ft_dda(data, x + 1, y);
			if (data->height - 1 > data->l->l_y_s)
				ft_dda(data, x, y + 1);
			data->l->l_x_s++;
			x++;
		}
		data->l->l_y_s++;
		y++;
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
			data->mlx_img->img, 0, 0);
	}
	ft_menu(data);
}
