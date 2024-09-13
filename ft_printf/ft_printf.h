/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:56:54 by cristinm          #+#    #+#             */
/*   Updated: 2023/11/29 14:03:12 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		handle_format(va_list args, char type);

int		print_char(char c);
int		print_string(char *s);
int		print_int(int n);
int		print_uint(unsigned int n);
int		print_hex(unsigned int n, int uppercase);
int		print_pointer(unsigned long long int n);

int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_putnbr_base(unsigned long long n, char *base);
int		count_digits(int n);
int		count_digitsu(unsigned int n);
int		ft_pchar(char c);
int		ft_strlen_mod(char *str);

#endif