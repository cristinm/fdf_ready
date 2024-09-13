/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:52:06 by cristinm          #+#    #+#             */
/*   Updated: 2023/11/29 11:12:00 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief: Prints an integer to the standard output.
* @param n: The integer to be printed.
* @return: The number of characters printed.
*/

#include "../ft_printf.h"

int	print_int(int n)
{
	int	aux;

	aux = ft_putnbr(n);
	if (aux == -1)
		return (-1);
	return (count_digits(n));
}
