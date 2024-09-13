/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:45:29 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:20:56 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Applies the function ’f’ to each character of the string ’s’ providing its
* index and a character as arguments and creates a string with the result.
* Returns: The dynamically allocated NEW string created, or NULL if the 
* allocation fails or if the string is empty.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_string;
	size_t			length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	new_string = malloc(sizeof(char) * length + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
/* 
#include <stdio.h>

char ft_just_to_check(unsigned int i, char c)
{
	return (ft_toupper(c));
}

int main(int argc, char **argv)
{
	char *result;

	if (argc != 2)
		return (1);
	result = ft_strmapi(argv[1], ft_just_to_check);
	printf("Resultado: %s\n", result);
	free(result);
	return (0);
} */