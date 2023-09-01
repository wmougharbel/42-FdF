/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:04:51 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/01 12:06:43 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->mlx_window, 10, 10, 0xffffff,
		"Move: W-S-A-D");
	mlx_string_put(data->mlx_ptr, data->mlx_window, 10, 35, 0xffffff,
		"Zoom: Mouse Wheel");
	mlx_string_put(data->mlx_ptr, data->mlx_window, 10, 60, 0xffffff,
		"Change View: Left Click");
	mlx_string_put(data->mlx_ptr, data->mlx_window, 10, 85, 0xffffff,
		"Change Depth: Arrow Up - Arrow Down");
}

void	color(t_fdf *data, float x_e, float y_e)
{
	char	**color;

	if (!ft_strchr(data->color_matrix[(int)data->l->l_y_s]
			[(int)data->l->l_x_s], ','))
	{	
		color = ft_split(data->color_matrix[(int)data->l->l_y_s]
			[(int)data->l->l_x_s], ',');
		data->color = hex_to_decimal(color[1]);
		free_arr(color);
	}
	else if (!ft_strchr(data->color_matrix[(int)y_e]
			[(int)x_e], ','))
	{
		color = ft_split(data->color_matrix[(int)data->l->l_y_s]
			[(int)data->l->l_x_s], ',');
		data->color = hex_to_decimal(color[1]);
		free_arr(color);
	}
	else
		def_color(data, data->l->z_s, data->l->z_e);
}

void	def_color(t_fdf *data, float z_start, float z_end)
{
	if ((z_start <= 2 && z_start > 0) || (z_end <= 2 && z_end > 0)
		|| (z_start >= -2 && z_start < 0) || (z_end >= -2 && z_end < 0))
		data->color = 0xEF8633;
	else if ((z_start <= 4 && z_start > 2) || (z_end <= 4 && z_end > 2)
		|| (z_start >= -4 && z_start < -2) || (z_end >= -4 && z_end < -2))
		data->color = 0x0033ff;
	else if ((z_start <= 6 && z_start > 4) || (z_end <= 6 && z_end > 4)
		|| (z_start >= -6 && z_start < -4) || (z_end >= -6 && z_end < -4))
		data->color = 0x00ccff;
	else if ((z_start <= 8 && z_start > 6) || (z_end <= 8 && z_end > 6)
		|| (z_start >= -8 && z_start < -6) || (z_end >= -8 && z_end < -6))
		data->color = 0x00ffff;
	else if ((z_start <= 10 && z_start > 8) || (z_end <= 10 && z_end > 8)
		|| (z_start >= -10 && z_start < -8) || (z_end >= -10 && z_end < -8))
		data->color = 0xF3AF3D;
	else if ((z_start <= 12 && z_start > 10) || (z_end <= 12 && z_end > 10)
		|| (z_start >= -12 && z_start < -10) || (z_end >= -10 && z_end < -8))
		data->color = 0x00ff99;
	else if ((z_start > 12) || (z_end > 12) || (z_start < -12) || (z_end < -12))
		data->color = 0x99ff00;
	else
		data->color = 0x9A1F6A;
}
