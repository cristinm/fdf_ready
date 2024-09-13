/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:03:43 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/26 19:52:13 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Adds a new node at the beginning of a linked list.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
/* 
#include <stdio.h>

void print_list(t_list *lst)
{
	t_list *current = lst; 
	while (current != NULL) 
	{
		printf("%d\n", *(int*)current->content);
		current = current->next;
	}
}

int main()
{
	t_list *head = NULL; 

	int n1 = 1;
	int n2 = 2;
	int n3 = 3;

	// create new nodes
	t_list *node1 = ft_lstnew(&n1);
	t_list *node2 = ft_lstnew(&n2);
	t_list *node3 = ft_lstnew(&n3);

	// add the new nodes to the front of the list
	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);

	// print the list
	print_list(head);
	
	return 0;
} */