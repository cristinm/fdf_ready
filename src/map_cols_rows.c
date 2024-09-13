/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cols_rows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:41:14 by cristinm          #+#    #+#             */
/*   Updated: 2024/09/13 16:58:32 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	count_rows(const char *buffer, t_data *data)
{
	const char	*ptr;

	ptr = buffer;
	data->rows = 0;
	while (*ptr)
	{
		if (*ptr == '\n')
		{
			data->rows++;
		}
		ptr++;
	}
	if (buffer[ft_strlen(buffer) - 1] != '\n')
	{
		data->rows++;
	}
}

void	count_cols(const char *buffer, t_data *data)
{
	const char	*line_start;
	const char	*line_end;
	int			col_count;
	const char	*ptr;
	const char	*col_end;

	line_start = buffer;
	line_end = ft_strchr(line_start, '\n');
	if (!line_end)
		line_end = buffer + ft_strlen(buffer);
	col_count = 0;
	ptr = line_start;
	while (ptr < line_end)
	{
		while (ptr < line_end && ft_is_space(*ptr))
			ptr++;
		if (ptr >= line_end)
			break ;
		col_end = ptr;
		while (col_end < line_end && !ft_is_space(*col_end))
			col_end++;
		col_count++;
		ptr = col_end;
	}
	data->cols = col_count;
}

int	count_rows_and_cols(const char *filename, t_data *data)
{
	data->buffer = NULL;
	data->buffer_size = 0;
	data->new_buffer_size = 0;
	data->new_buffer = NULL;
	if (!read_file_to_buffer(filename, data))
		return (-1);
	count_rows(data->buffer, data);
	count_cols(data->buffer, data);
	free(data->buffer);
	return (0);
}
