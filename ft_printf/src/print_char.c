/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:51:12 by cristinm          #+#    #+#             */
/*   Updated: 2023/11/29 11:12:08 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief: Prints a character to the standard output.
* @param c: The character to be printed.
* @return: The number of characters printed.
*/

#include "../ft_printf.h"

int	print_char(char c)
{
	return (ft_pchar(c));
}
