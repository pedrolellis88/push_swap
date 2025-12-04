/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_doubled.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:14:00 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/25 17:42:11 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_doubled(t_list *a)
{
	t_list	*copy;
	t_list	*search;

	copy = a;
	while (copy)
	{
		search = copy->next;
		while (search)
		{
			if (*(int *)copy->content == *(int *)search->content)
				return (0);
			search = search->next;
		}
		copy = copy->next;
	}
	return (1);
}
/*int	main(void)
{
	t_list	*a = NULL;
	int		*x;
	int		*y;
	int		*z;

	x = malloc(sizeof(int));
	y = malloc(sizeof(int));
	z = malloc(sizeof(int));
	*x = 3;
	*y = 2;
	*z = -3; 

	ft_lstadd_back(&a, ft_lstnew(x));
	ft_lstadd_back(&a, ft_lstnew(y));
	ft_lstadd_back(&a, ft_lstnew(z));
	ft_printf("%d\n", is_doubled(a)); 

}*/
