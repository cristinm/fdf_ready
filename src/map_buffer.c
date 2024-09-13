/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:03:47 by cristinm          #+#    #+#             */
/*   Updated: 2024/08/24 14:12:20 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*resize_buffer(t_data *data, size_t total_read, size_t new_size)
{
	char	*new_buffer;

	new_buffer = malloc(new_size);
	if (!new_buffer)
		return (free(data->buffer), NULL);
	ft_memcpy(new_buffer, data->buffer, total_read);
	free(data->buffer);
	data->buffer = new_buffer;
	data->buffer_size = new_size;
	return (new_buffer);
}

int	read_and_expand_buffer(int file, t_data *data, size_t *total_read)
{
	ssize_t	bytes_read;
	size_t	new_buffer_size;

	bytes_read = read(file, data->temp_buffer, sizeof(data->temp_buffer));
	while (bytes_read > 0)
	{
		if (*total_read + bytes_read > data->buffer_size)
		{
			new_buffer_size = data->buffer_size;
			while (*total_read + bytes_read > new_buffer_size)
				new_buffer_size *= 2;
			if (!resize_buffer(data, *total_read, new_buffer_size))
				return (-1);
		}
		ft_memcpy(data->buffer + *total_read, data->temp_buffer, bytes_read);
		*total_read += bytes_read;
		bytes_read = read(file, data->temp_buffer, sizeof(data->temp_buffer));
	}
}

char	*read_file_to_buffer(const char *filename, t_data *data)
{
	int		file;
	size_t	total_read;
	ssize_t	bytes_read;

	file = open(filename, O_RDONLY);
	total_read = 0;
	if (file < 0)
		return (ft_printf("Error opening file"), NULL);
	data->buffer_size = 1024;
	data->buffer = malloc(data->buffer_size);
	if (!data->buffer)
		return (close(file), NULL);
	bytes_read = read_and_expand_buffer(file, data, &total_read);
	if (bytes_read < 0)
		return (close(file), free(data->buffer), NULL);
	data->buffer[total_read] = '\0';
	close(file);
	return (data->buffer);
}
