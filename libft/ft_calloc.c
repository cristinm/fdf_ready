/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:05:40 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/21 13:53:14 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Allocates memory for an array of elements and initializes the memory to zero.
* nmemb: number of elements to allocate.
* size: size of each element.
* Return: a pointer to the allocated memory. Null if nmemb is 0 or malloc fails.
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && SIZE_MAX / size < nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*  
#include <stdio.h>
#include <stdlib.h>

 int main(int argc, char **argv)
 {
	 if (argc != 3) {
		 char error[] = "Error\n";
		 printf("%s", error);
		 return 1;
	 }
 
	 int i = 0;
	 char *str;
 
	 str = ft_calloc(atoi(argv[1]), atoi(argv[2]));
	 printf("str after ft_calloc: ");
	 i = 0;
	 while (i < atoi(argv[1])) {
		 printf("%d", str[i]);
		 i++;
	 }
	 printf("\n");
 
	 str = calloc(atoi(argv[1]), atoi(argv[2]));
	 printf("str after calloc: ");
	 i = 0;
	 while (i < atoi(argv[1])) {
		 printf("%d", str[i]);
		 i++;
	 }
	 printf("\n");
 
	 return 0;
 }
  */