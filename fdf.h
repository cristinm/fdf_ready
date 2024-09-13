/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:52:22 by cristinm          #+#    #+#             */
/*   Updated: 2024/08/24 17:37:04 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define COS_ANG 0.86602540378	// cos(M_PI / 6)
# define SIN_ANG 0.5			// sin(M_PI / 6)
# define WIDTH  1920
# define LENGTH 1080

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <limits.h>

typedef struct s_point
{
	double	x;
	double	y;
	int		z;
}	t_point;

typedef struct s_line
{
	t_point	p1;
	t_point	p2;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	double	length;
	int		current_x;
	int		current_y;
	int		t_x1;
	int		t_x2;
	int		t_y1;
	int		t_y2;
	int		row1;
	int		col1;
	int		row2;
	int		col2;
}	t_line;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bpp;
	int		endian;
	int		l_len;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		fd;
	int		**grid;
	t_point	**iso_grid;
	int		**colors;
	int		rows;
	int		cols;
	double	sc;
	int		off_x;
	int		off_y;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	int		min_z;
	int		max_z;
	int		width;
	int		height;
	int		start_color;
	int		end_color;
	double	margin_x;
	double	margin_y;
	double	adjusted_width;
	double	adjusted_height;
	double	grid_width;
	double	grid_height;
	char	*buffer;
	size_t	buffer_size;
	char	temp_buffer[1024];
	size_t	new_buffer_size;
	char	*new_buffer;
}	t_data;

void	adjust_to_window(t_data *data);
int		**allocate_colors(t_data *data);
t_point	**allocate_iso_grid(t_data *data);
int		**allocate_grid(t_data *data);
void	calculate_margins_and_grid_dimensions(t_data *data);
int		calculate_max_z(t_data *data);
int		calculate_min_z(t_data *data);
void	calculate_offsets(t_data *data);
double	calculate_progress(t_line *line);
void	calculate_range(t_data *data);
double	calculate_scale(t_data *data);
int		check_file_exists_and_is_readable(const char *filename);
int		check_file_extension(const char *filename);
int		check_map(const char *filename);
void	cleanup(t_data *data);
int		close_esc(int keysym, t_data *data);
int		close_x(t_data *data);
void	count_cols(const char *buffer, t_data *data);
int		count_rows_and_cols(const char *filename, t_data *data);
void	draw_iso_grid(t_data *data);
void	draw_line(t_data *data, t_line *line);
void	draw_lines_down(t_data *data, int row);
void	draw_lines_to_the_right(t_data *data, int row);
int		fill_and_transform_grid(const char *filename, t_data *data);
void	free_colors(int **colors, int rows);
void	free_grid(int **grid, int rows);
void	free_iso_grid(t_point **grid, int rows);
void	initialize_data(t_data *data);
int		init_mlx_resources(t_data *data);
void	init_line(t_line *line);
void	init_line_points(t_line *line);
int		interpolate_color(t_data *data, t_line *line, double progress);
void	iso_transform_grid(t_data *data);
void	pixel_put_opt(t_img *img, int x, int y, int color);
int		process_map(const char *filename, t_data *data);
int		process_colors_in_line(t_data *data, char *line, int row);
int		process_line(t_data *data, char *line, int row);
int		read_and_expand_buffer(int file, t_data *data, size_t *total_read);
int		read_and_fill_grid(t_data *data, const char *filename);
int		read_and_fill_colors(t_data *data, const char *filename);
char	*read_file_to_buffer(const char *filename, t_data *data);
void	render_line(t_data *data, t_line *line);
char	*resize_buffer(t_data *data, size_t total_read, size_t new_size);
void	update_min_max(t_data *data, t_point current_point, int current_z);

#endif