/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:50:59 by cristinm          #+#    #+#             */
/*   Updated: 2024/08/22 18:20:19 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	calculate_min_z(t_data *data)
{
	int	min_z;
	int	i;
	int	j;

	min_z = data->grid[0][0];
	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->grid[i][j] < min_z)
			{
				min_z = data->grid[i][j];
			}
			j++;
		}
		i++;
	}
	return (min_z);
}

int	calculate_max_z(t_data *data)
{
	int	max_z;
	int	i;
	int	j;

	max_z = data->grid[0][0];
	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->grid[i][j] > max_z)
			{
				max_z = data->grid[i][j];
			}
			j++;
		}
		i++;
	}
	return (max_z);
}

void	update_min_max(t_data *data, t_point current_point, int current_z)
{
	if (current_point.x < data->min_x)
		data->min_x = current_point.x;
	if (current_point.x > data->max_x)
		data->max_x = current_point.x;
	if (current_point.y < data->min_y)
		data->min_y = current_point.y;
	if (current_point.y > data->max_y)
		data->max_y = current_point.y;
	if (current_z < data->min_z)
		data->min_z = current_z;
	if (current_z > data->max_z)
		data->max_z = current_z;
}

void	calculate_range(t_data *data)
{
	int		row;
	int		col;
	t_point	current_point;
	int		current_z;

	row = 0;
	while (row < data->rows)
	{
		col = 0;
		while (col < data->cols)
		{
			current_point = data->iso_grid[row][col];
			current_z = data->grid[row][col];
			update_min_max(data, current_point, current_z);
			col++;
		}
		row++;
	}
}
