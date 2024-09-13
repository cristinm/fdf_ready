/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:19:51 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:08:54 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Appends the NUL-terminated string src to the end of dst with a specified size.
* If the length of the concatenated string exceeds the size, the string will be 
* truncated. It assumes that destination has enough space for n characters and
* the null terminator. (It may overflows if not).
* Returns the total length of the string it tried to create. 
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_length;
	size_t	src_length;
	size_t	i;
	size_t	j;

	dest_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	i = 0;
	j = dest_length;
	if (size == 0 || size <= dest_length)
		return (src_length + size);
	while (src[i] != '\0' && i < size - dest_length - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dest_length + src_length);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	unsigned int	result;
	(void)argc;

	result = ft_strlcat(argv[1], argv[2], atoi(argv[3]));
	printf("Result: %d\n", result);
	printf("Concatenated strings: %s\n", argv[1]);
}  */