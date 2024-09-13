/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:01:48 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/26 20:00:44 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Deletes a node from a linked list and frees the memory of the node's content.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}
/* 
static void    del(void *data_to_delete)
{
	free(data_to_delete);
} 

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

    printf("List before deleting node:\n");
    ft_print_list(lst);

    if (lst)
    {
        t_list *temp = lst;
        lst = lst->next;
        ft_lstdelone(temp, del);
    }

    printf("List after deleting node:\n");
    ft_print_list(lst);

    return 0;
} */