/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:33:14 by cristinm          #+#    #+#             */
/*   Updated: 2024/08/23 13:01:19 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	**allocate_grid(t_data *data)
{
	int	**grid;
	int	row_index;
	int	col_index;

	grid = (int **)malloc(data->rows * sizeof(int *));
	if (!grid)
		return (NULL);
	row_index = 0;
	while (row_index < data->rows)
	{
		grid[row_index] = (int *)malloc(data->cols * sizeof(int));
		if (!grid[row_index])
		{
			free_grid(grid, row_index);
			return (NULL);
		}
		col_index = 0;
		while (col_index < data->cols)
		{
			grid[row_index][col_index] = 0;
			col_index++;
		}
		row_index++;
	}
	return (grid);
}

t_point	**allocate_iso_grid(t_data *data)
{
	t_point	**iso_grid;
	int		i;

	iso_grid = (t_point **)malloc(data->rows * sizeof(t_point *));
	if (!iso_grid)
		return (NULL);
	i = 0;
	while (i < data->rows)
	{
		iso_grid[i] = (t_point *)malloc(data->cols * sizeof(t_point));
		if (!iso_grid[i])
		{
			while (--i >= 0)
			{
				free(iso_grid[i]);
			}
			free(iso_grid);
			return (NULL);
		}
		i++;
	}
	return (iso_grid);
}

int	**allocate_colors(t_data *data)
{
	int	**colors;
	int	row_index;
	int	col_index;

	colors = (int **)malloc(data->rows * sizeof(int *));
	if (!colors)
		return (NULL);
	row_index = 0;
	while (row_index < data->rows)
	{
		colors[row_index] = (int *)malloc(data->cols * sizeof(int));
		if (!colors[row_index])
		{
			free_colors(colors, row_index);
			return (NULL);
		}
		col_index = 0;
		while (col_index < data->cols)
		{
			colors[row_index][col_index] = 0;
			col_index++;
		}
		row_index++;
	}
	return (colors);
}
