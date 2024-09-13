/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:52:42 by cristinm          #+#    #+#             */
/*   Updated: 2023/11/29 11:11:43 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief: Prints an unsigned integer to the standard output.
* @param n: The unsigned integer to be printed.
* @return: The number of characters printed.
*/

#include "../ft_printf.h"

int	print_uint(unsigned int n)
{
	int	aux;

	if (n == 0)
	{
		aux = ft_pchar('0');
		if (aux == -1)
			return (-1);
	}
	if (n > 0)
	{
		aux = ft_putunbr(n);
		if (aux == -1)
			return (-1);
	}
	return (count_digitsu(n));
}
