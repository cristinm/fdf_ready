/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:42:51 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 13:47:57 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Checks if the passed character is alphabetic.
* It returns 1 if the character is alphabetic, otherwise 0.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/* 
#include <ctype.h> //Library for isalpha function
#include <stdio.h>

int main(int ac, char **av)
{
	if(ac == 2)
	{
	printf("Result using ft_isalpha: %i\n",ft_isalpha(av[1][0]));
	printf("Result using isalpha: %i\n", isalpha(av[1][0]));
	}
	return (0);
} */