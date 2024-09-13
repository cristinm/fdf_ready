/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:07:10 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 14:08:07 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* Compares the first n bytes of the memory areas s1 and s2.
* Returns: the difference between the first two differing bytes or 0 if they are 
* all equal. If the value is positive, the first differing byte in s1 is greater.
* If the value is negative, the first differing byte in s1 is lesser.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
/* 
#include <stdio.h>
#include <string.h> //Libreria para memcmp
#include <stdlib.h> //Library for atoi

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	int result = ft_memcmp(argv[1], argv[2], atoi(argv[3]));
	printf("Resultado: %d\n", result);
	int result2 = memcmp(argv[1], argv[2], atoi(argv[3]));
	printf("Resultado: %d\n", result2);
	return (0);
}*/