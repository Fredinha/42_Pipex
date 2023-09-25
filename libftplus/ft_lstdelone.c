/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:42:00 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/11 20:46:06 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free (lst);
		lst = NULL;
	}
}

/*void	del(void *content)
{
	//free(content);
	content = NULL;
}

int   main(void)
{
        t_list  *l1 = malloc(sizeof(t_list));
        t_list  *l2 = malloc(sizeof(t_list));
        t_list  *l3 = malloc(sizeof(t_list));
        t_list  *current;
       
        char    *a = "fred";
        char    *b = "fofa";
        char  	*c = "cute";
        l1->content = a;
        l2->content = b;
        l3->content = c;
        l1->next = l2;
        l2->next = l3;
        l3->next = NULL;
        current = l1;
        ft_lstdelone(l3, del);
	while (current->next)
	{
        	printf("%s\n", (char *)current->content);
		current = current->next;
	}
        free(l1);
	free(l2);
}*/
