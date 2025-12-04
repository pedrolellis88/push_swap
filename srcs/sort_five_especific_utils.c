/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_especific_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:18:33 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/12/01 13:02:00 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_list *a, int i)
{
	int		j;

	j = 0;
	while (a)
	{
		if (*(int *)a->content == i)
			return (j);
		a = a->next;
		j++;
	}
	return (-1);
}

int	find_smallest(t_list *a)
{
	int	smallest;

	if (!a)
		return (0);
	smallest = *(int *)a->content;
	a = a->next;
	while (a)
	{
		if (*(int *)a->content < smallest)
			smallest = *(int *)a->content;
		a = a->next;
	}
	return (smallest);
}

void	push_smallest_to_top(t_list **a, int i, t_data *data)
{
	int	position;
	int	size;
	int	x;

	position = find_position(*a, i);
	size = ft_lstsize(*a);
	if (position == 0)
		return ;
	if (position <= size / 2)
	{
		while (position--)
			ra(data);
	}
	else
	{
		x = size - position ;
		while (x--)
			rra(data);
	}
}
