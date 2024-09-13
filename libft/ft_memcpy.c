/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:41:35 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:44:53 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Copies n bytes from a memory block from the source to the destination.
* The memory areas must not overlap. (Use memmove instead if they do).
* Returns: original pointer to the destination memory block.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/* 
#include <stdio.h> 
#include <stddef.h> //Libreria para size_t
#include <string.h> //Libreria para memcpy

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
	ft_memcpy(argv[1], argv[2], len + 1); // +1 to include '\0'
	printf("Destination after ft_memcpy: %s\n", argv[1]);
	memcpy(argv[1], argv[2], len + 1);
	printf("Destination after memcpy: %s\n", argv[1]);

	return 0;
}*/