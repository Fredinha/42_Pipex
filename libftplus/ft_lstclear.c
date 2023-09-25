/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:59:48 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/11 20:52:45 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst && del)
	{
		current = *lst;
		while (current)
		{
			next = current->next;
			del(current->content);
			free (current);
			current = next;
		}
		*lst = NULL;
	}
}

/*void 	del(void *content)
{
	content = NULL;
}

int     main(void)
{
        t_list  *l1 = malloc(sizeof(t_list));
        t_list  *l2 = malloc(sizeof(t_list));
        t_list  *l3 = malloc(sizeof(t_list));
        t_list  *current;

        int     a = 1;
        int     b = 2;
        int     c = 3;

        l1->content = (void *)&a;
        l2->content = (void *)&b;
        l3->content = (void *)&c;
        l1->next = l2;
        l2->next = l3;
        l3->next = NULL;
        ft_lstclear(&l1, del);
        current = l1;
        while (current)
        {
                printf("%d\n", *(int *)current->content);
                current = current->next;
        }
       // free(l1);
       // free(l2);
       // free(l3);
}*/
