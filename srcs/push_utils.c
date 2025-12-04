/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:44:04 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/26 15:04:37 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push(t_list **src, t_list **dest)
{
	t_list	*node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = node->next;
	node->next = *dest;
	*dest = node;
}

void	pa(t_data *data)
{
	push(&data->b, &data->a);
	ft_printf("pa\n");
}

void	pb(t_data *data)
{
	push(&data->a, &data->b);
	ft_printf("pb\n");
}
