/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:22:30 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/26 19:53:31 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Counts the number of nodes in a linked list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
/* 
#include <stdio.h>

int main(void)
{
    t_list *lst = NULL;
	int size = 0;
    
    int n1 = 1;
	int n2 = 2;
	int n3 = 3;

	t_list *node1 = ft_lstnew(&n1);
	t_list *node2 = ft_lstnew(&n2);
	t_list *node3 = ft_lstnew(&n3);

	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);

    size = ft_lstsize(lst);

    printf("Size of the list: %d\n", size);

    return (0);
} */