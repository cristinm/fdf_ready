/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:47:45 by cristinm          #+#    #+#             */
/*   Updated: 2023/11/29 11:19:05 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* ft_pchar
* @brief: Prints a character to the standard output.
* @param c: The character to be printed.
* @return: Number of characters printed or -1 if write error.
*
* ft_strlen
* @brief: Counts the number of characters of a string.
* @param str: The string to be counted.
* @return: The number of characters of the string.
*/

#include "../ft_printf.h"

int	ft_pchar(char c)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (result);
}

int	ft_strlen_mod(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}
