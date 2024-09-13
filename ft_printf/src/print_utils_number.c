/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:47:45 by cristinm          #+#    #+#             */
/*   Updated: 2024/06/03 18:52:29 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* count_digits
* @brief: Counts the number of digits of an integer.
* @param n: The integer to be counted.
* @return: The number of digits of the integer.
*
* count_digitsu
* @brief: Counts the number of digits of an unsigned integer.
* @param n: The unsigned integer to be counted.
* @return: The number of digits of the unsigned integer.
*
* ft_putnbr
* @brief: Prints an integer to the standard output.
* @param n: The integer to be printed.
* @return: Number of characters printed or -1 if write error.
*
* ft_putunbr
* @brief: Prints an unsigned integer to the standard output.
* @param n: The unsigned integer to be printed.
* @return: Number of characters printed or -1 if write error.
*
* ft_putnbr_base
* @brief: Prints an unsigned integer to the standard output in the given base.
* @param n: The unsigned integer to be printed.
* @param base: The base in which the integer will be printed.
* @return: Number of characters printed or -1 if write error.
*/

#include "../ft_printf.h"

int	count_digits(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		length++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

int	count_digitsu(unsigned int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

int	ft_putnbr(int n)
{
	int	aux;

	aux = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		aux = ft_pchar('-');
		if (aux == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		aux = ft_putnbr(n / 10);
		if (aux == -1)
			return (-1);
		aux = ft_pchar(n % 10 + '0');
		if (aux == -1)
			return (-1);
	}
	else
		return (ft_pchar(n + '0'));
	return (aux);
}

int	ft_putunbr(unsigned int n)
{
	int	aux;

	aux = 0;
	if (n >= 10)
	{
		aux = ft_putunbr(n / 10);
		if (aux == -1)
			return (-1);
	}
	aux = ft_pchar(n % 10 + '0');
	if (aux == -1)
		return (-1);
	return (aux);
}

int	ft_putnbr_base(unsigned long long int n, char *base)
{
	int	length;
	int	aux;

	length = 0;
	aux = 0;
	if (n >= (unsigned long long int)ft_strlen_mod(base))
	{
		length += ft_putnbr_base(n / ft_strlen_mod(base), base);
		aux = length;
		if (aux == -1)
			return (-1);
		length += ft_putnbr_base(n % ft_strlen_mod(base), base);
		aux = length;
		if (aux == -1)
			return (-1);
	}
	else
	{
		aux = ft_pchar(base[n]);
		if (aux == -1)
			return (-1);
		length++;
	}
	return (length);
}
