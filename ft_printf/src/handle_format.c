/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:27:40 by cristinm          #+#    #+#             */
/*   Updated: 2023/11/29 17:06:43 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief: Handles the formatting of an argument from a variable argument list 
* based on the type.
* @param args: A variable argument list.
* @param type: The type of the argument (c, d, i, s, u, x, X, p, %).
* @return: The result of the print function corresponding to the type or -1 if 
* the type is not valid.
*/

#include "../ft_printf.h"

int	handle_format(va_list args, char type)
{
	int	result;

	result = -1;
	if (type == 'c')
		result = print_char(va_arg(args, int));
	else if (type == 'd' || type == 'i')
		result = print_int(va_arg(args, int));
	else if (type == 's')
		result = print_string(va_arg(args, char *));
	else if (type == 'u')
		result = print_uint(va_arg(args, unsigned int));
	else if (type == 'x')
		result = print_hex(va_arg(args, unsigned int), 0);
	else if (type == 'X')
		result = print_hex(va_arg(args, unsigned int), 1);
	else if (type == 'p')
		result = print_pointer(va_arg(args, unsigned long long));
	else if (type == '%')
	{
		if (ft_pchar('%') == -1)
			return (-1);
		return (1);
	}
	return (result);
}
