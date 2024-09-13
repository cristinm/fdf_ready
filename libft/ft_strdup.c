/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:06:31 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 14:57:16 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Creates a duplicate of a string.
* Returns a pointer to the newly allocated string or NULL if allocation fails.
* Use of free() is mandatory after usage.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	int		i;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	if (s_len > SIZE_MAX)
		s_len = SIZE_MAX;
	i = 0;
	sdup = (char *)malloc(sizeof(char) * s_len);
	if (!sdup)
		return (NULL);
	while (s[i])
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}
/* 
#include <stdio.h>
#include <string.h> //for strdup
#include <stdlib.h> //for free

int main(int argc, char **argv)
{
	if (argc != 2) {
		char error[] = "Error\n";
		printf("%s", error);
		return 1;
	}

	char *str;
	str = ft_strdup(argv[1]);
	printf("Result after ft_strdup: %s\n", str);
	free(str);
	char *str2;
	str2 = (char *)strdup(argv[1]);
	printf("Result after strdup: %s\n", str2);
	free(str2);
	return 0;
} */