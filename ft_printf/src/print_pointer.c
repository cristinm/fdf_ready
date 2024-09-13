/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:53:39 by cristinm          #+#    #+#             */
/*   Updated: 2023/11/29 14:03:06 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief: Prints the hexadecimal representation of a pointer (memory address)to 
the standard output. The function prefixes the hexadecimal value with "0x" 
to indicate that it is an hexadecimal number.
* @param n: The pointer to be printed.
* @return: The number of characters printed, included the 0x prefix.
*/

#include "../ft_printf.h"

int	print_pointer(unsigned long long n)
{
	int	length;
	int	aux;

	aux = 0;
	if (n == 0)
	{
		aux = write(1, "0x0", 3);
		if (aux == -1)
			return (-1);
		return (aux);
	}
	else
	{
		aux = write(1, "0x", 2);
		if (aux == -1)
			return (-1);
		length = ft_putnbr_base(n, "0123456789abcdef");
		return (length + 2);
	}
}
