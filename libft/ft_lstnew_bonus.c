/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:58:13 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/26 19:45:16 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Adds a new node at the beginning of a linked list.
* Returns: 
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/* 
#include <stdio.h>

int	main(void)
{
	t_list	*node;

	node = ft_lstnew("New node's content");
	printf("%s\n", (char *)node->content);
	return (0);
} */