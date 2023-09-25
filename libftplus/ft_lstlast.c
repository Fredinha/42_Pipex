/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:11:43 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/11 19:19:48 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int   main(void)
{
        t_list  *l1 = malloc(sizeof(t_list));
        t_list  *l2 = malloc(sizeof(t_list));
        t_list  *l3 = malloc(sizeof(t_list));
        t_list  *current;
 	t_list	*last;

        char	*a;
	char	*b;
	char	*c;
   	a = "fred";
	b = "fofa";
	c = "cute";
   	l1->content = a;
        l2->content = b;
        l3->content = c;
        l1->next = l2;
        l2->next = l3;
        l3->next = NULL;
        current = l1;
	last = ft_lstlast(l1);
        printf("%s\n", (char *)last->content);
        free(l1);
}*/
