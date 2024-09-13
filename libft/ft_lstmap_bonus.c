/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:57:30 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/27 08:51:51 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Iterates the linked list lst and applies the function f to the content of
* each node. Creates a new list resulting of the successive applications of
* the function f.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*content;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		new = ft_lstnew(content);
		if (!new)
		{
			(*del)(content);
			ft_lstclear(&first, del);
			return (0);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
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

void *multiply_by_two(void *num)
{
    int *n = (int *)num;
    int *result = malloc(sizeof(int));
    *result = (*n) * 2;
    return result;
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

    printf("List before mapping:\n");
    ft_print_list(lst);

	// Llamar a ft_lstmap
    t_list *result = ft_lstmap(lst, multiply_by_two, del);

    printf("List after mapping:\n");
    ft_print_list(result);

    // Liberar la memoria de la lista original y el resultado
    ft_lstclear(&lst, del);
    ft_lstclear(&result, del);

    return 0;
} */