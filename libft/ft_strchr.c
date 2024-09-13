/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:47:32 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 14:55:57 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Locates the first occurrence of a character in a given string.
* Returns a pointer to the located character, or NULL if no match was found. If
* c is '\0', the function returns a pointer to the terminator.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	else
		return (NULL);
}
/*
#include <string.h> //Library for strchr
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	char *result = ft_strchr(argv[1], argv[2][0]);
	printf("Resultado: %s\n", result);
	char *result2 = strchr(argv[1], argv[2][0]);
	printf("Resultado: %s\n", result2);
	return (0);
}*/
