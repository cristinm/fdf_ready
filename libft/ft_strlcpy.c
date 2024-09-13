/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:43:54 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:11:43 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Copies a null-terminated string from src to dst, ensuring proper null 
* termination within a limited size. It assumes that destination has enough 
* space for n characters and the null terminator. (It may overflows if not).
* Returns the length of the src string.
*/

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/* 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int result;
    
    if (argc != 4) {
        char error[] = "Error\n";
        printf("%s", error);
        return (1);
    }
    result = ft_strlcpy(argv[1], argv[2], atoi(argv[3]));
    printf("Result: %d\n", result);
    printf("Destination after ft_strlcpy: %s\n", argv[1]);
    return 0;
}*/