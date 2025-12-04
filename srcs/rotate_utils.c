/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:38:33 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/26 15:56:34 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate(t_list **a_or_b)
{
	t_list	*first;
	t_list	*last;

	if (!a_or_b || !*a_or_b || !(*a_or_b)->next)
		return ;
	first = *a_or_b;
	*a_or_b = first->next;
	first->next = NULL;
	last = ft_lstlast(*a_or_b);
	last->next = first;
}

void	ra(t_data *data)
{
	rotate(&data->a);
	ft_printf("ra\n");
}

void	rb(t_data *data)
{
	rotate(&data->b);
	ft_printf("rb\n");
}

void	rr(t_data *data)
{
	rotate(&data->a);
	rotate(&data->b);
	ft_printf("rr\n");
}
