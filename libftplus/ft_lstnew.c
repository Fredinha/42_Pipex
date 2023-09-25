/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:36:29 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/11 18:42:06 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*int	main(void)
{
	t_list	*l1 = malloc(sizeof(t_list));
	t_list	*l2 = malloc(sizeof(t_list));
	t_list	*l3 = malloc(sizeof(t_list)); 
	t_list	*current;
	int	content = 4;
	int	a = 1;
	int	b = 2;
	int	c = 3;

	l1->content = (void *)&a;
	l2->content = (void *)&b;
	l3->content = (void *)&c;
	l1->next = l2;
	l2->next = l3;
	l3->next = ft_lstnew(&content);
	current = l1;
	while (current)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}
	free(l1);
	free(l2);
	free(l3);
}*/
