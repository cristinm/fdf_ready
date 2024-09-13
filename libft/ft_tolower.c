/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:44:39 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:40:30 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Converts the passed character to lowercase.
* Returns: the lowercase equivalent of the character.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/* 
#include <stdio.h>

 int main(int argc, char **argv)
 {
	 (void)argc;
	 char input;
	 
	 input = argv[1][0];
	 printf("Uncapitalized: %c\n", ft_tolower(input));
 } */