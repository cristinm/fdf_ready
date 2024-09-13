/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:22:18 by cristinm          #+#    #+#             */
/*   Updated: 2024/08/23 14:18:28 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	calculate_scale(t_data *data)
{
	double	scale_x;
	double	scale_y;
	double	min_scale;

	calculate_margins_and_grid_dimensions(data);
	if (data->grid_width <= 0)
		scale_x = data->adjusted_width;
	else
		scale_x = data->adjusted_width / data->grid_width;
	if (data->grid_height <= 0)
		scale_y = data->adjusted_height;
	else
		scale_y = data->adjusted_height / data->grid_height;
	if (scale_x <= 0)
		scale_x = 1.0;
	if (scale_y <= 0)
		scale_y = 1.0;
	min_scale = scale_x;
	if (scale_y < scale_x)
		min_scale = scale_y;
	return (min_scale);
}

void	calculate_offsets(t_data *data)
{
	double	grid_center_x;
	double	grid_center_y;
	double	window_center_x;
	double	window_center_y;

	grid_center_x = (data->min_x + data->max_x) / 2.0;
	grid_center_y = (data->min_y + data->max_y) / 2.0;
	window_center_x = WIDTH / 2.0;
	window_center_y = LENGTH / 2.0;
	data->off_x = (int)(window_center_x - (grid_center_x * data->sc));
	data->off_y = (int)(window_center_y - (grid_center_y * data->sc));
}

void	adjust_to_window(t_data *data)
{
	data->min_z = calculate_min_z(data);
	data->max_z = calculate_max_z(data);
	calculate_range(data);
	data->sc = calculate_scale(data);
	calculate_offsets(data);
}

void	calculate_margins_and_grid_dimensions(t_data *data)
{
	data->margin_x = WIDTH * 0.1;
	data->margin_y = LENGTH * 0.1;
	data->adjusted_width = WIDTH - data->margin_x;
	data->adjusted_height = LENGTH - data->margin_y;
	data->grid_width = data->max_x - data->min_x;
	data->grid_height = data->max_y - data->min_y;
}
