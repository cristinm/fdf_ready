/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:00:38 by cristinm          #+#    #+#             */
/*   Updated: 2024/08/23 12:46:40 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	hex_to_int(const char *hex)
{
	int		result;
	int		value;
	char	c;

	result = 0;
	while (*hex)
	{
		c = *hex++;
		if (c >= '0' && c <= '9')
			value = c - '0';
		else if (c >= 'a' && c <= 'f')
			value = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			value = c - 'A' + 10;
		else
			return (-1);
		result = (result * 16) + value;
	}
	return (result);
}

int	extract_color(const char *str)
{
	const char	*color_start;

	color_start = ft_strnstr(str, "0x", ft_strlen(str));
	if (color_start != NULL)
	{
		return (hex_to_int(color_start + 2));
	}
	return (0);
}

int	process_colors_in_line(t_data *data, char *line, int row)
{
	char	**line_values;
	int		col;
	int		i;
	char	*color_ptr;

	line_values = ft_split(line, ' ');
	if (line_values == NULL)
		return (ft_printf("Error splitting line\n"), -1);
	col = 0;
	i = 0;
	while (line_values[i] != NULL && col < data->cols)
	{
		color_ptr = ft_strchr(line_values[i], ',');
		if (color_ptr != NULL)
			data->colors[row][col] = extract_color(color_ptr);
		else
			data->colors[row][col] = 0xFFFFFF;
		free(line_values[i]);
		col++;
		i++;
	}
	free(line_values);
	return (0);
}

int	read_and_fill_colors(t_data *data, const char *filename)
{
	char	*line;
	int		row;

	data->fd = open(filename, O_RDONLY);
	if (data->fd == -1)
		return (ft_printf("Error opening file\n"), -1);
	row = 0;
	line = get_next_line(data->fd);
	while (line != NULL && row < data->rows)
	{
		if (process_colors_in_line(data, line, row) == -1)
			return (free(line), close(data->fd), -1);
		free(line);
		row++;
		line = get_next_line(data->fd);
	}
	close(data->fd);
	return (0);
}

int	interpolate_color(t_data *data, t_line *line, double progress)
{
	int	color1;
	int	color2;
	int	interpolated_color;

	color1 = data->colors[line->row1][line->col1];
	color2 = data->colors[line->row2][line->col2];
	interpolated_color = color1 + (int)((color2 - color1) * progress);
	return (interpolated_color);
}
