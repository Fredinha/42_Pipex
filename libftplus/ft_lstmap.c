/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:27:24 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/11 21:31:48 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	new_element = NULL;
	while (lst)
	{
		new_element = ft_lstnew(f(lst->content));
		if (!new_element)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}

/*void	del(void *content)
{
	free(content);
}

void	*f(void *content)
{
	int	*new = malloc(sizeof(int));
	*new = *(int *)content * 2;
	return (void *)new;
}

int	main(void)
{
	t_list	*l1 = malloc(sizeof(t_list));
	t_list	*l2 = malloc(sizeof(t_list));
	t_list	*l3 = malloc(sizeof(t_list));
	t_list	*new_list;
	t_list	*current;
	int	a = 1;
	int	b = 2;
	int	c = 3;

	l1->content = (void *)&a;
	l2->content = (void *)&b;
	l3->content = (void *)&c;
	l1->next = l2;
	l2->next = l3;
	l3->next = NULL;
	new_list = ft_lstmap(l1, f, del);
	current = new_list;
	while (current)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}
	free(l1);
}*/
