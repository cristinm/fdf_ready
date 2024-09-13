/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:33:55 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:13:51 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Calculates the length of a string excluding the terminating null byte ('\0').
* Returns: the number of characters in the string.
*/

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}
/* 
#include <string.h> //Library for strlen
#include <stdio.h>

int main(int argc, char **argv)
{
	size_t length;
	
	if (argc != 2)
		return (0);
	length = ft_strlen(argv[1]);
	printf("The length of the string is: %zu\n", length);
	printf("The length of the string using strlen is: %zu\n", strlen(argv[1]));
	return (0);
} */
