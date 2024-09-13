/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:57:32 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 14:59:48 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Applies the function ’f’ to each character of the string ’s’ providing its
* index and a pointer to the character as arguments.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	length;

	if (!s || !f)
		return ;
	i = 0;
	length = ft_strlen(s);
	while (i < length)
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
#include <stdio.h>

void ft_just_to_check(unsigned int i, char *c)
{
    *c = ft_toupper(*c);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    else
    {
        ft_striteri(argv[1], &ft_just_to_check);
        printf("Result \'%s\'\n", argv[1]);    
    }
    return (0);
} */