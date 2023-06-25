/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:06:10 by wmoughar          #+#    #+#             */
/*   Updated: 2023/06/04 15:56:05 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_line
{
	float	x_s;
	float	y_s;
	float	x_e;
	float	y_e;
	float	z_s;
	float	z_e;
	int		l_x_s;
	int		l_y_s;
	int		l_x_e;
	int		l_y_e;
}			t_line;

typedef struct s_fdf
{
	char	***color_matrix;
	int		**z_matrix;
	char	*map;
	void	*mlx_ptr;
	void	*mlx_window;
	int		window_x;
	int		window_y;
	int		height;
	int		width;
	int		map_size;
	int		position_x;
	int		position_y;
	int		color;
	float	zoom;
	float	projection;
	float	depth;
	t_line	*l;
	t_data	*mlx_img;
}			t_fdf;

float		p(float num);
void		ft_menu(t_fdf *data);
int			ft_close(t_fdf *data);
bool		check_map(char *map);
void		free_everything(t_fdf *data);
void		free_arr(char **arr);
void		illustrate(t_fdf *data);
int			hex_to_decimal(char *hex);
int			s(float num1, float num2);
int			key_controls(int key, t_fdf *data);
void		read_map(t_fdf *data, char *map);
void		fill_arr(t_fdf *data, char **arr);
void		mlx_image(t_fdf *data, int x, int y);
bool		ft_error(int error, int ac, char *map);
void		ft_dda(t_fdf *data, float x_e, float y_e);
void		color(t_fdf *data, float x_e, float y_e);
int			mouse_controls(int key, int x, int y, t_fdf *data);
void		def_color(t_fdf *data, float z_start, float z_end);

#endif
