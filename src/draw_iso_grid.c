/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:58:00 by cristinm          #+#    #+#             */
/*   Updated: 2024/08/22 17:44:22 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_lines_to_the_right(t_data *data, int row)
{
	int		j;
	t_line	line;

	j = 0;
	while (j < data->cols - 1)
	{
		line.t_x1 = data->iso_grid[row][j].x * data->sc + data->off_x;
		line.t_y1 = data->iso_grid[row][j].y * data->sc + data->off_y;
		line.t_x2 = data->iso_grid[row][j + 1].x * data->sc + data->off_x;
		line.t_y2 = data->iso_grid[row][j + 1].y * data->sc + data->off_y;
		line.p1.z = data->iso_grid[row][j].z;
		line.p2.z = data->iso_grid[row][j + 1].z;
		line.row1 = row;
		line.col1 = j;
		line.row2 = row;
		line.col2 = j + 1;
		render_line(data, &line);
		j++;
	}
}

void	draw_lines_down(t_data *data, int row)
{
	int		j;
	t_line	line;

	j = 0;
	while (j < data->cols)
	{
		if (row < data->rows - 1)
		{
			line.t_x1 = data->iso_grid[row][j].x * data->sc + data->off_x;
			line.t_y1 = data->iso_grid[row][j].y * data->sc + data->off_y;
			line.t_x2 = data->iso_grid[row + 1][j].x * data->sc + data->off_x;
			line.t_y2 = data->iso_grid[row + 1][j].y * data->sc + data->off_y;
			line.p1.z = data->iso_grid[row][j].z;
			line.p2.z = data->iso_grid[row + 1][j].z;
			line.row1 = row;
			line.col1 = j;
			line.row2 = row + 1;
			line.col2 = j;
			render_line(data, &line);
		}
		j++;
	}
}

void	draw_iso_grid(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		draw_lines_to_the_right(data, i);
		draw_lines_down(data, i);
		i++;
	}
}
