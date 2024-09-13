/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:26:57 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:22:55 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Compares two strings up to a specified lenght.
* Returns: 0 if they are equal, a positive value if s1 is greater than s2, or a
* negative value if s1 is lesser than s2.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/* 
#include <stddef.h> //Library for size_t
#include <string.h> //Library for strncmp
#include <stdlib.h> //Library for atoi
#include <stdio.h> 

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	int result = ft_strncmp(argv[1], argv[2], atoi(argv[3]));
	printf("Resultado: %d\n", result);
	int result2 = strncmp(argv[1], argv[2], atoi(argv[3]));
	printf("Resultado: %d\n", result2);
	return (0);
} */