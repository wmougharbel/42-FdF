/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:04:25 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/01 12:06:07 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_height(t_fdf *data)
{
	int		fd;
	char	*line;

	data->height = 0;
	fd = open(data->map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	get_width(t_fdf *data)
{
	int		fd;
	char	*line;
	char	**string;

	data->width = 0;
	fd = open(data->map, O_RDONLY);
	line = get_next_line(fd);
	string = ft_split(line, ' ');
	while (string[data->width] && string[data->width][0] != '\n')
		data->width++;
	data->map_size = data->width * data->height;
	free(line);
	free_arr(string);
	close(fd);
}

void	fill_matrix(t_fdf *data)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**string;

	i = 0;
	fd = open(data->map, O_RDWR);
	data->z_matrix = malloc(sizeof(int *) * data->height);
	while (data->height > i)
	{
		j = 0;
		line = get_next_line(fd);
		string = ft_split(line, ' ');
		data->z_matrix[i] = malloc(sizeof(int) * data->width);
		while (data->width > j)
		{
			data->z_matrix[i][j] = ft_atoi(string[j]);
			j++;
		}
		i++;
		free(line);
		free_arr(string);
	}
	close(fd);
}

void	color_matrix(t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;
	char	**string;

	i = 0;
	fd = open(data->map, O_RDWR);
	data->color_matrix = malloc(sizeof(char **) * data->height + 1);
	while (data->height > i)
	{
		line = get_next_line(fd);
		string = ft_split(line, ' ');
		data->color_matrix[i] = malloc(sizeof(char *) * data->width + 1);
		fill_arr(data, string);
		free(line);
		free_arr(string);
		i++;
	}
	data->color_matrix[i] = NULL;
	close(fd);
}

void	read_map(t_fdf *data, char *map)
{
	ft_printf("Launching...\n");
	data->map = map;
	get_height(data);
	get_width(data);
	fill_matrix(data);
	color_matrix(data);
}
