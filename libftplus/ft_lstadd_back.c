/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:21:14 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/11 19:01:37 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

/*int     main(void)
{
        t_list  *l1 = malloc(sizeof(t_list));
        t_list  *l2 = malloc(sizeof(t_list));
        t_list  *l3 = malloc(sizeof(t_list));
        t_list  *current;
        t_list  *lnew = malloc(sizeof(t_list));

        int     content = 8;
        int     a = 1;
        int     b = 2;
        int     c = 3;

        l1->content = (void *)&a;
        l2->content = (void *)&b;
        l3->content = (void *)&c;
        lnew->content = (void *)&content;
        l1->next = l2;
        l2->next = l3;
        l3->next = NULL;
        ft_lstadd_back(&l1, lnew);
        current = l1;
        while (current)
        {
                printf("%d\n", *(int *)current->content);
                current = current->next;
        }
       // free(l1);
       // free(l2);
       // free(l3);
        free(l1);
}*/
