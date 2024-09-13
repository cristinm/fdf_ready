/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:53:21 by cristinm          #+#    #+#             */
/*   Updated: 2023/11/29 11:12:04 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief: Prints to the standard output the hexadecimal representation of an
* unsigned int.
* @param n: The unsigned integer to be printed.
* @param uppercase: A flag to print the hexadecimal in uppercase/lowercase.
* @return: The number of characters printed.
*/

#include "../ft_printf.h"

int	print_hex(unsigned int n, int uppercase)
{
	char	*hex_digits;
	char	*hex_digits_lower;
	char	*hex_digits_upper;
	int		count;

	hex_digits_upper = "0123456789ABCDEF";
	hex_digits_lower = "0123456789abcdef";
	if (uppercase == 1)
		hex_digits = hex_digits_upper;
	else
		hex_digits = hex_digits_lower;
	count = ft_putnbr_base(n, hex_digits);
	return (count);
}
