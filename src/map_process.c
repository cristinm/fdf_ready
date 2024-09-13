/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:25:06 by cristinm          #+#    #+#             */
/*   Updated: 2024/09/13 13:00:31 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	process_line(t_data *data, char *line, int row)
{
	char	**line_values;
	int		col;
	int		i;

	line_values = ft_split(line, ' ');
	if (line_values == NULL)
	{
		ft_printf("Error splitting line\n");
		return (-1);
	}
	col = 0;
	i = 0;
	while (line_values[i] != NULL && col < data->cols)
	{
		data->grid[row][col] = ft_atoi(line_values[i]);
		free(line_values[i]);
		col++;
		i++;
	}
	free(line_values);
	return (0);
}

int	read_and_fill_grid(t_data *data, const char *filename)
{
	char	*line;
	int		row;

	data->fd = open(filename, O_RDONLY);
	if (data->fd == -1)
	{
		ft_printf("Error opening file\n");
		return (-1);
	}
	row = 0;
	line = get_next_line(data->fd);
	while (line != NULL && row < data->rows)
	{
		if (process_line(data, line, row) == -1)
		{
			free (line);
			close(data->fd);
			return (-1);
		}
		row++;
		free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
	return (0);
}

void	iso_transform_grid(t_data *data)
{
	int	row;
	int	col;
	int	subtraction;
	int	sum;

	row = 0;
	while (row < data->rows)
	{
		col = 0;
		while (col < data->cols)
		{
			subtraction = col - row;
			sum = col + row;
			data->iso_grid[row][col].x = subtraction * COS_ANG;
			data->iso_grid[row][col].y = sum * SIN_ANG - data->grid[row][col];
			data->iso_grid[row][col].z = data->grid[row][col];
			col++;
		}
		row++;
	}
}

int	fill_and_transform_grid(const char *filename, t_data *data)
{
	if (read_and_fill_grid(data, filename) == -1)
		return (-1);
	iso_transform_grid(data);
	if (read_and_fill_colors(data, filename) == -1)
		return (-1);
	return (0);
}

int	process_map(const char *filename, t_data *data)
{
	if (count_rows_and_cols(filename, data) == -1)
		return (-1);
	data->grid = allocate_grid(data);
	if (!data->grid)
		return (-1);
	data->iso_grid = allocate_iso_grid(data);
	if (!data->iso_grid)
	{
		free_grid(data->grid, data->rows);
		return (-1);
	}
	data->colors = allocate_colors(data);
	if (data->colors == NULL)
		return (-1);
	if (fill_and_transform_grid(filename, data) == -1)
	{
		free_grid(data->grid, data->rows);
		free_iso_grid(data->iso_grid, data->rows);
		free_colors(data->colors, data->rows);
		return (-1);
	}
	return (0);
}
