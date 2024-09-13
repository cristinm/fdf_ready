/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:32:18 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 13:57:02 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Sets the first n bytes of the area starting at s to zero.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 3) {
		char error[] = "Error\n";
		printf("%s", error);
		return (1);
	}

	int i = 0;
	char str[100];
	ft_bzero(str, atoi(argv[2]));
	printf("str after ft_bzero: ");
	i = 0;
	while (i < atoi(argv[2])) {
		printf("%d", str[i]);
		i++;
	}
	printf("\n");

	bzero(str, atoi(argv[2]));
	printf("str after bzero: ");
	i = 0;
	while (i < atoi(argv[2])) {
		printf("%d", str[i]);
		i++;
	}
	printf("\n");

	return 0;
} */