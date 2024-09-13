/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:24:43 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/27 08:50:13 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Checks if the passed character is ASCII.
* It returns 1 if the character is ASCII, otherwise 0. 
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	return (0);
}
/* 
#include <ctype.h> //Library for isascii function
#include <stdio.h>

int main(int ac, char **av)
{
	if(ac == 2)
	{
	printf("Result using ft_isascii: %i\n",ft_isascii(av[1][0]));
	printf("Result using isascii: %i\n", isascii(av[1][0]));
	}
	return (0);
} */