/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:55:07 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/27 17:54:43 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	reverse_rotate(t_list **a_or_b)
{
	t_list	*last_but_one;
	t_list	*last;
	t_list	*temp;

	if (!a_or_b || !*a_or_b || !(*a_or_b)->next)
		return ;
	temp = *a_or_b;
	while (temp->next->next)
		temp = temp->next;
	last_but_one = temp;
	last = temp->next;
	last_but_one->next = NULL;
	last->next = *a_or_b;
	*a_or_b = last;
}

void	rra(t_data *data)
{
	reverse_rotate(&data->a);
	ft_printf("rra\n");
}

void	rrb(t_data *data)
{
	reverse_rotate(&data->b);
	ft_printf("rrb\n");
}

void	rrr(t_data *data)
{
	reverse_rotate(&data->a);
	reverse_rotate(&data->b);
	ft_printf("rrr\n");
}
