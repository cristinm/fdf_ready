/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:13:30 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 13:48:22 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Checks if the passed character is alphanumeric.
* It returns 1 if the character is alphanumeric, otherwise 0.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/* 
#include <ctype.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if(ac == 2)
	{
	printf("Result using ft_isalnum: %i\n",ft_isalnum(av[1][0]));
	printf("Result using isalnum: %i\n", isalnum(av[1][0]));
	}
	return (0);
} */