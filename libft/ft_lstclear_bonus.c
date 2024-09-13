/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:21:58 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/26 19:49:50 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Deletes and frees a given node from a linked list and every element after it.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	if (!lst || !del || !(*lst))
		return ;
	node = *lst;
	while (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
}
/* 
#include <stdio.h>

static void    del(void *data_to_delete)
{
	free(data_to_delete);
} 

void ft_print_list(t_list *lst)
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
	t_list *lst = NULL;
	
	int *element1 = malloc(sizeof(int));
    *element1 = 1;
    lst = ft_lstnew(element1);

    int *element2 = malloc(sizeof(int));
    *element2 = 2;
    ft_lstadd_back(&lst, ft_lstnew(element2));

    int *element3 = malloc(sizeof(int));
    *element3 = 3;
    ft_lstadd_back(&lst, ft_lstnew(element3)); 

    printf("List before clearing list:\n");
    ft_print_list(lst);

	ft_lstclear(&lst, del);
	
	printf("List after clearing list:\n");
	ft_print_list(lst);
	
	return (0);
} */