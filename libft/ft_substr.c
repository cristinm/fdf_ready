/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:33:19 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:39:21 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Creates a substring from a string given a start index and a length.
* Returns: a pointer to the substring if mem alloc succeeds or if len is zero.
* If the allocation fails or the start index is out of range, returns NULL.
* Use of free() is mandatory after usage.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;
	size_t	j;

	slen = ft_strlen(s);
	if (slen < start)
		len = 0;
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = start;
	j = 0;
	while (i < slen && j < len)
	{
		sub[j] = s[i];
		j++;
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *sub;

    if (argc != 4) {
        char error[] = "Error\n";
        printf("%s", error);
        return 1;
    }
    sub = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
    printf("%s\n", sub);
    free(sub);
    return 0;
} */