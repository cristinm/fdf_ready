/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:53:19 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/27 08:50:39 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Converts an integer to a string.
* Returns a dynamically allocated string that represents the integer and NULL 
* if the allocation fails.
*/

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		length++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static char	*ft_handle_int_min(char **string)
{
	free(*string);
	*string = (char *)malloc(sizeof(char) * 12);
	if (!*string)
		return (NULL);
	ft_strlcpy(*string, "-2147483648", 12);
	return (*string);
}

char	*ft_itoa(int n)
{
	char	*string;
	size_t	length;

	length = ft_count_digits(n);
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (!string)
		return (NULL);
	string[length] = '\0';
	if (n == -2147483648)
		ft_handle_int_min(&string);
	else if (n == 0)
		string[0] = '0';
	else if (n < 0)
	{
		string[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		string[length - 1] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	return (string);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	if (argc == 2) 
	{
		char *result = ft_itoa(atoi(argv[1]));
		if (result) {
			printf("%s\n", result);
			free(result); // We need to free the memory allocated by ft_itoa.
		} else {
			printf("Error: Memory not allocated.\n");
		}
	}
	return 0;
} */