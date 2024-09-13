/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:46:17 by cristinm          #+#    #+#             */
/*   Updated: 2023/11/29 11:12:21 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief: This function prints a formatted string to the standard output.
* @param format: A pointer to a null-terminated format string.
* @param ...: Variable number of arguments to be formatted.
* @return: The total number of characters printed, or -1 if an error occurs.
*/

#include "../ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;
	int		result;
	int		aux;

	count = 0;
	aux = 0;
	va_start(args, str);
	while (*str && count >= 0)
	{
		if (*str == '%')
		{
			str++;
			result = handle_format(args, *str++);
			count += result;
		}
		else
		{
			aux = ft_pchar(*str++);
			if (aux == -1)
				return (-1);
			count++;
		}
	}
	return (va_end(args), count);
}
