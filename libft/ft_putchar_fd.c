/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:22:30 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 14:22:55 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Outputs the character ’c’ to the given file descriptor.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}
/* 
int main(void)
{
	char c = 'A';
	int fd = STDOUT_FILENO;

	ft_putchar_fd(c, fd);
	return (0);
} */