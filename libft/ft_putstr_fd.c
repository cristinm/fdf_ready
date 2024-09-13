/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:49:03 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 14:25:58 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Outputs the string ’s’ to the given file descriptor.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
/*  
int main(int argc, char **argv)
{
	(void) argc;
	ft_putstr_fd(argv[1], STDOUT_FILENO);
} */