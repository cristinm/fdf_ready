/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:16:36 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:29:24 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Locates the last occurrence of a character in a given string.
* Returns a pointer to the located character, or NULL if no match was found. If
* c is '\0', the function returns a pointer to the terminator.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_occurrence = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last_occurrence);
}
/*
#include <stddef.h> //Library for size_t
#include <string.h> //Library for strrchr
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	char *result = ft_strrchr(argv[1], argv[2][0]);
	printf("Resultado: %s\n", result);
	char *result2 = strrchr(argv[1], argv[2][0]);
	printf("Resultado: %s\n", result2);
	return (0);
} */
