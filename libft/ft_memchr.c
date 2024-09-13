/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:39:14 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 14:03:20 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Locates the first occurrence of a character in a memory block.
* Returns a pointer to the located character, or NULL if no match was found.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)ptr + i);
		i++;
	}
	return (NULL);
}
/* 
#include <stdio.h>
#include <string.h> //Libreria para memchr
#include <stdlib.h> //Library for atoi

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	void *result = ft_memchr(argv[1], argv[2][0], atoi(argv[3]));
	printf("Resultado: %p\n", result);
	void *result2 = memchr(argv[1], argv[2][0], atoi(argv[3]));
	printf("Resultado: %p\n", result2);
	return (0);
}*/