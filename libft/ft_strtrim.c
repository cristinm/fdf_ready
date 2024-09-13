/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:40:18 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 15:34:34 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Trims the leading and trailing characters from a string s1 that match any 
* character in set. It allocates memory for the trimmed string, copies the 
* non-matching characters from s1 to the new string, adds a null terminator.
* Returns the pointer to the trimmed string if the allocation succeeds and 
* the trimmed string is not empty. If s1 or set is NULL, allocation fails, or
* the trimmed string is empty, returns NULL.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;

	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (0);
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *end))
		end--;
	return (ft_substr(start, 0, (end - start + 1)));
}
/* 
#include <stdio.h>

int main(int argc, char **argv)
{
	char *result;

	if (argc != 3)
		return (1);
	result = ft_strtrim(argv[1], argv[2]);
	printf("%s\n", result);
	return (0);
} */
