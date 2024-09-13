/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 08:43:01 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:40:46 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Converts the passed character to uppercase.
* Returns: the uppercase equivalent of the character.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/* 
#include <stdio.h>

 int main(int argc, char **argv)
 {
	 (void)argc;
	 char input;
	 
	 input = argv[1][0];
	 printf("Capitalized: %c\n", ft_toupper(input));
 } */