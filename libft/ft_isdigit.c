/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:26:46 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/27 08:50:21 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Checks if the passed character is a digit.
* It returns 1 if the character is a digit, otherwise 0.
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/* 
#include <ctype.h> //Library for isdigit function
#include <stdio.h>

int main(int ac, char **av)
{
	if(ac == 2)
	{
	printf("Result using ft_isdigit: %i\n",ft_isdigit(av[1][0]));
	printf("Result using isdigit: %i\n", isdigit(av[1][0]));
	}
	return (0);
} */