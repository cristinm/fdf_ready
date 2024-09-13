/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:29:10 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/27 08:50:28 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Checks if the passed character is printable. 
* It returns 1 if the character is printable, otherwise 0.
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}
/* 
#include <ctype.h> //Library for isprint function
#include <stdio.h>

int main(int ac, char **av)
{
	if(ac == 2)
	{
	printf("Result using ft_isprint es: %i\n",ft_isprint(av[1][0]));
	printf("Result using isprint es: %i\n", isprint(av[1][0]));
	}
	return (0);
} */