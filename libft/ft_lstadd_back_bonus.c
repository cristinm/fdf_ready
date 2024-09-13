/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:46:01 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/26 19:55:36 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Adds a new node at the end of a linked list.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/* 
#include <stdio.h>

void ft_print_list(t_list *lst)
{
	t_list *current = lst;
	while (current != NULL)
	{
		printf("%d\n", *(int*)current->content);
		current = current->next;
	}
}

int	main()
{
	t_list *lst = NULL;
    
    int n1 = 1;
	int n2 = 2;
	int n3 = 3;

	t_list *node1 = ft_lstnew(&n1);
	t_list *node2 = ft_lstnew(&n2);
	t_list *node3 = ft_lstnew(&n3);
	
	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	ft_lstadd_back(&lst, node3); 

	ft_print_list(lst);
	
	return 0;
} */