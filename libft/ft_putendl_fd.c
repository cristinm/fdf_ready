/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:58:49 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 14:24:50 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Outputs the string ’s’ to the given file descriptor, followed by a newline.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/* 
int main(int argc, char **argv)
{
	(void) argc;
	ft_putendl_fd(argv[1], STDOUT_FILENO);
} */