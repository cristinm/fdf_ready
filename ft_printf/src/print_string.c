/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:51:42 by cristinm          #+#    #+#             */
/*   Updated: 2023/11/29 11:12:57 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief: Prints a string to the standard output.
* @param s: The string to be printed.
* @return: The number of characters printed. If the string is NULL, it returns
* 6, the number of characters of "(null)".
*/

#include "../ft_printf.h"

int	print_string(char *s)
{
	int	aux;

	aux = 0;
	if (s == NULL)
	{
		aux = write (1, "(null)", 6);
		if (aux == -1)
			return (-1);
		return (aux);
	}
	aux = write (1, s, ft_strlen_mod(s));
	if (aux == -1)
		return (-1);
	return (aux);
}
