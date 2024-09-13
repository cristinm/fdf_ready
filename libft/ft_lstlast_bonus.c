/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:30:27 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/26 19:54:20 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Returns the last node of a linked list.
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/* 
#include <stdio.h>

int	main()
{
	t_list *head = NULL;

	int n1 = 1;
	int n2 = 2;
	int n3 = 3;

	t_list *node1 = ft_lstnew(&n1);
	t_list *node2 = ft_lstnew(&n2);
	t_list *node3 = ft_lstnew(&n3);

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	t_list *last = ft_lstlast(head);
	printf("The last node's content is: %d\n", *(int*)last->content);

	return (0);
} */