/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:57:12 by cristinm          #+#    #+#             */
/*   Updated: 2023/10/26 19:50:34 by cristinm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Iterates the linked list lst and applies the function f to the content of
* each node.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
/* 
#include <stdio.h>

void multiply_by_two(void *content)
{
    int *num = (int *)content;
    *num *= 2;
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

int	main(void)
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
	printf("List before iterating:\n");
	ft_print_list(lst);
	ft_lstiter(lst, multiply_by_two);
	printf("List after iterating:\n");
	ft_print_list(lst);
	return (0);
}  */