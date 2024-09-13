/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:26:37 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 14:18:19 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Fills the first n bytes of a memory block with the specified value. 
* Returns: a pointer to the memory block after it has been filled.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 4) {
		char error[] = "Error\n";
		printf("%s", error);
		return 1;
	}

	char character = argv[2][0]; 
	size_t size = atoi(argv[3]); 
	char str[100]; 

	ft_memset(str, character, size);
	printf("str after ft_memset: %s\n", str);
	memset(str, character, size);
	printf("str after memset: %s\n", str);
	return 0;
}*/