/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:18:25 by wmoughar          #+#    #+#             */
/*   Updated: 2023/06/03 16:56:11 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//*-p takes the number and returns its absolute value. Stands for positive
//*-s checks wich one is the greater number of steps to implement 
//the dda algorithm
//*-had to name them like this because fuck norminette that's why!
//*-converting the type to int in the end of s to have an integer of steps

float	p(float num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	s(float num1, float num2)
{
	if (num1 > num2)
		return (num1);
	return ((int)num2);
}

void	free_everything(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
		free(data->z_matrix[i++]);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
			free(data->color_matrix[i][j++]);
		free(data->color_matrix[i]);
		i++;
	}
	free(data->color_matrix);
	free(data->z_matrix);
	free(data->mlx_img);
	free(data->l);
	free(data);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

bool	ft_error(int error, int ac, char *map)
{
	if (error == 1 && ac == 1)
	{
		ft_printf("%sERROR: missing map argument!\n", "\e[31m");
		exit(1);
	}
	else if (error == 2 && check_map(map) == false)
	{
		ft_printf("%sERROR: Invalid Map!\n", "\e[31m");
		exit(1);
	}
	else if (error == 1 && ac != 2)
	{
		ft_printf("%sERROR: Invalid number of arguments!\n", "\e[31m");
		exit(1);
	}
	else
		return (true);
}
