/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:52:08 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 14:16:03 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Copies n bytes from a memory block from the source to the destination.
* The memory areas may overlap: the bytes in the source are first copied into
* a temporary array, then from the temporary array to the destination.
* Returns: original pointer to the destination memory block.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		while (n > 0)
		{
			n--;
			destination[n] = source[n];
		}
	}
	else
	{
		while (n > 0)
		{
			*destination++ = *source++;
			n--;
		}
	}
	return (dst);
}
/* #include <stdio.h>
#include <string.h> //Libreria for memcpy

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		char error[] = "Error\n";
		printf("%s", error);
		return 1;
	}

	size_t len = ft_strlen(argv[1]);
	ft_memmove(argv[1], argv[2], len + 1); // +1 to include '\0'
	printf("Destination after ft_memmove: %s\n", argv[1]);
	memmove(argv[1], argv[2], len + 1);
	printf("Destination after memmove: %s\n", argv[1]);

	return 0;
} */
