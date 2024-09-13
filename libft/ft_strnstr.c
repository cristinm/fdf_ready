/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:13:36 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:28:22 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Locates the first occurrence of a substring within a string, up to a 
* specified length.
* Returns: a pointer to the first occurrence of str2 in str1, or NULL if the 
* substring is not found or if len is zero.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
/* 
#include <stdlib.h> //Libreria para atoi
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	char *result = ft_strnstr(argv[1], argv[2], atoi(argv[3]));
	printf("Resultado: %s\n", result);
	return (0);
}*/