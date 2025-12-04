/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:06:01 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/26 14:35:40 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_list **a_or_b)
{
	t_list	*first;
	t_list	*second;

	if (!a_or_b || !*a_or_b || !(*a_or_b)->next)
		return ;
	first = *a_or_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a_or_b = second;
}

void	sa(t_data *data)
{
	swap(&data->a);
	ft_printf("sa\n");
}

void	sb(t_data *data)
{
	swap(&data->b);
	ft_printf("sb\n");
}

void	ss(t_data *data)
{
	swap(&data->a);
	swap(&data->b);
	ft_printf("ss\n");
}
