/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:47:24 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:01:35 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Joins two strings into a new string.
* Returns: a pointer to the new string or NULL if the allocation fails or if
* any of the strings is NULL.
* Use of free() is mandatory after usage.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	total_length;

	if (!s1 || !s2)
		return (NULL);
	total_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = (char *)malloc(sizeof(char) * total_length);
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, total_length);
	ft_strlcat(joined, s2, total_length);
	return (joined);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *joined;

	if (argc != 3) {
		char error[] = "Error\n";
		printf("%s", error);
		return (1);
	}
	joined = ft_strjoin(argv[1], argv[2]);
	printf("Joined string: %s\n", joined);
	if (!joined)
		return (1);
	free(joined);
	return (0);
} */
