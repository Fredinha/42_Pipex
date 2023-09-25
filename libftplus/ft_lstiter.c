/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:16:21 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/11 21:11:28 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst && f)
	{
		current = lst;
		while (current)
		{
			f(current->content);
			next = current->next;
			current = next;
		}
	}
}

/*void	f(void *content)
{
	*(void**)content = NULL ;
}

int	main(void)
{
	t_list	*l1 = malloc(sizeof(t_list));
	t_list	*l2 = malloc(sizeof(t_list));
	t_list	*l3 = malloc(sizeof(t_list));
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
	current = l1;
	ft_lstiter(l1, f);
	while (current)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}
	free(l1);
}*/
