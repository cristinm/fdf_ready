/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:41:38 by cristinm          #+#    #+#             */
/*   Updated: 2024/09/13 13:41:25 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* get_next_line
* @brief: reads the next line from a file.
* @param fd: the file descriptor to the file to read from.
* @return: a pointer to the string that contains the next line read from the 
* file. NULL if the end of the file is reached or if an error occurs.
*
* read_block
* @brief: reads a block of data from a file. It continues reading until it
* encounters a newline character or reaches the end of the file.
* @param fd: the file descriptor of the file to read from.
* @param str: a pointer to the string where the data read will be appended.
* @return: a pointer to the string that contains the data read or NULL if
* an error occurs.
*
* get_until_nl
* @brief: extracts a line from a string. A line is defined as a sequence of 
* characters ending in a newline
* @param storage: a pointer to the string from which the line will be extracted.
* @return: a pointer to the string that contains the line extracted from the
* input string.
*
* get_leftovers
* @brief: extracts any remaining data from a string after a newline character
* is encountered.
* @param storage: a pointer to the string from which the remaining data will be
* extracted.
* @return: a pointer to the string that contains the remaining data extracted
* from the input string.
*/

#include "libft.h"
#include "../ft_printf/ft_printf.h"

char	*join_strings(char *str, char *temp)
{
	char	*new_str;

	if (str)
		new_str = ft_strjoin(str, temp);
	else
		new_str = ft_strdup(temp);
	if (!new_str)
	{
		free(temp);
		if (str)
			free(str);
		return (NULL);
	}
	if (str)
		free(str);
	return (new_str);
}

char	*read_block(int fd, char *str)
{
	char	*temp;
	int		bytes_read;

	temp = allocate_temp();
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && (!str || !ft_strchr_mod(str, '\n')))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (handle_read_error(temp, str));
		temp[bytes_read] = '\0';
		str = join_strings(str, temp);
		if (!str)
			return (NULL);
	}
	free(temp);
	return (str);
}

char	*get_until_nl(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	if (!storage || !storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_leftovers(char *storage)
{
	char	*leftovers;
	int		i;
	int		j;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	leftovers = malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!leftovers)
	{
		free(storage);
		return (NULL);
	}
	i++;
	j = 0;
	while (storage[i] != '\0')
		leftovers[j++] = storage[i++];
	leftovers[j] = '\0';
	free(storage);
	return (leftovers);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_printf("Invalid file descriptor or buffer size\n");
		return (NULL);
	}
	storage = read_block(fd, storage);
	if (!storage)
	{
		ft_printf("Error reading block\n");
		return (NULL);
	}
	next_line = get_until_nl(storage);
	if (!next_line)
		return (NULL);
	storage = get_leftovers(storage);
	return (next_line);
}
