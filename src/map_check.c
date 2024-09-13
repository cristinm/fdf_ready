/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:40:12 by cristinm          #+#    #+#             */
/*   Updated: 2024/09/13 14:01:53 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	check_file_extension(const char *filename)
{
	int		len;
	char	*extension;

	len = ft_strlen(filename);
	extension = ".fdf";
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, extension, 4) == 0)
		return (1);
	else
		return (0);
}

int	check_file_exists_and_is_readable(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	else
	{
		return (0);
	}
}

int	check_map(const char *filename)
{
	if (check_file_extension(filename) != 1)
	{
		ft_printf("Error: Wrong extension.\n");
		return (-1);
	}
	if (check_file_exists_and_is_readable(filename) != 1)
	{
		ft_printf("Error: File does not exist or is not readable.\n");
		return (-1);
	}
	return (0);
}
