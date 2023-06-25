/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:43:50 by wmoughar          #+#    #+#             */
/*   Updated: 2023/06/03 20:24:21 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	check_map(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (map[i - 1] == 'f' && map[i - 2] == 'd' && map[i - 3] == 'f' && map[i
			- 4] == '.' && open(map, O_RDONLY) == 3)
		return (true);
	return (false);
}

int	hex_to_decimal(char *hex)
{
	char	**arr;
	int		decimal;
	int		i;
	int		len;
	int		val;

	decimal = 0;
	i = 0;
	arr = ft_split(hex, '\n');
	len = ft_strlen(arr[0]);
	while (i < len)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			val = hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			val = hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			val = hex[i] - 'A' + 10;
		else
			val = 0;
		decimal = decimal * 16 + val;
		i++;
	}
	free_arr(arr);
	return (decimal);
}

void	fill_arr(t_fdf *data, char **arr)
{
	static int	i;
	int			j;
	int			k;

	j = 0;
	while (data->width > j)
	{
		k = 0;
		data->color_matrix[i][j] = malloc(sizeof(char) * ft_strlen(arr[j]));
		while (arr[j][k])
		{
			data->color_matrix[i][j][k] = arr[j][k];
			k++;
		}
		data->color_matrix[i][j][k] = '\0';
		j++;
	}
	data->color_matrix[i][j] = NULL;
	i++;
}

void	mlx_image(t_fdf *data, int x, int y)
{
	if (x || y)
		mlx_destroy_image(data->mlx_ptr, data->mlx_img->img);
	if (x + y == 0)
		ft_printf("%sDone!", "\e[4;32m");
	data->mlx_img->img = mlx_new_image(data->mlx_ptr, 4096, 2160);
	data->mlx_img->addr = mlx_get_data_addr(data->mlx_img->img,
			&data->mlx_img->bits_per_pixel,
			&data->mlx_img->line_length,
			&data->mlx_img->endian);
	illustrate(data);
}
