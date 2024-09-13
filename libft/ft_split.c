/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:30:25 by cristinm          #+#    #+#             */
/*   Updated: 2024/08/20 16:43:17 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Splits ’str’ using the character ’c’ as a delimiter.
* Returns the array of the substrings resulting from the split or NULL if the 
* allocation fails or if the string is empty.
* Use of free() is mandatory after usage.
*/

#include "libft.h"

static size_t	ft_word_count(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (!str[i])
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	len_c(char *str, char c)
{
	char	*current_char;
	size_t	length;

	current_char = str;
	length = 0;
	if (!*current_char)
		return (0);
	while (*current_char)
	{
		if (*current_char == c)
			return (length);
		length++;
		current_char++;
	}
	return (length);
}

static void	ft_free_array(char **array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	ft_word_copy(char *dst, const char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	**ft_split(char const *str, char c)
{
	char	**arr;
	size_t	num_words;
	size_t	i;

	num_words = ft_word_count((char *)str, c);
	arr = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*str && num_words > 0)
	{
		if (len_c((char *)str, c) == 0)
			str++;
		else
		{
			arr[i] = (char *)malloc(sizeof(char) * (len_c((char *)str, c) + 1));
			if (!arr[i])
				return (ft_free_array(arr, i), NULL);
			ft_word_copy(arr[i], str, len_c((char *)str, c));
			str = str + len_c((char *)str, c);
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
/* 
#include <stdio.h>
int main(int argc, char **argv)
{
    char **array;
    int i;

    if (argc != 3)
        return (0);
    array = ft_split(argv[1], argv[2][0]);
    i = 0;
    while (array[i])
    {
        printf("%s\n", array[i]);
        i++;
    }
    free(array);
    return (0);
} */