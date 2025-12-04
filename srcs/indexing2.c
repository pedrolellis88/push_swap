/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:01:42 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/12/01 15:38:27 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_list *a)
{
	int	max;

	if (!a)
		return (0);
	max = *(int *)a->content;
	a = a->next;
	while (a)
	{
		if (*(int *)a->content > max)
			max = *(int *)a->content;
		a = a->next;
	}
	return (max);
}

int	max_bits(t_list *a)
{
	int	max;
	int	bits;

	max = find_max_index(a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix(t_data *data)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	size = ft_lstsize(data->a);
	bits = max_bits(data->a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*(int *)data->a->content >> i) & 1) == 0 && data->a)
				pb(data);
			else
				ra(data);
			j++;
		}
		while (data->b != NULL)
			pa(data);
		i++;
	}
}
