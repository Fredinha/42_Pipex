/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:06:07 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/11 19:05:23 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*int   main(void)
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
        current = l1;
         printf("%d\n", ft_lstsize(l1));
        free(l1);
}*/
