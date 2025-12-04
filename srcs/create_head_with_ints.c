/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_head_with_ints.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:37:38 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/26 10:57:27 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	*validate(int *p, t_list **head)
{
	if (p)
		free(p);
	if (head && *head)
		ft_lstclear(head, free);
	return (NULL);
}

t_list	*create_head_with_ints(int c, char **v)
{
	t_list	*head;
	t_list	*node;
	int		i;
	int		*content;
	int		value;

	head = NULL;
	i = 0;
	while (i < c)
	{
		if (is_str_valid(v[i]) == 0)
			return (validate(NULL, &head));
		content = malloc(sizeof(int));
		if (!content)
			return (validate(NULL, &head));
		if (safe_atoi(v[i], &value) == 0)
			return (validate(content, &head));
		*content = value;
		node = ft_lstnew(content);
		if (!node)
			return (validate(content, &head));
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}
/*
void	print(void *p)
{
	ft_printf("%i\n", *(int *)p);
}

int	main(int c, char **v)
{	
	t_list	*test;

	if (c > 1)
	{
		test = create_head_with_ints(c, v);
		ft_lstiter(test, print);
	}
}*/
