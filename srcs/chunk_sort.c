/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:46:21 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/12/04 15:23:12 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	bring_max_to_top(t_data *data)
{
	int	size;
	int	max;
	int	position;

	size = ft_lstsize(data->b);
	max = find_max_index(data->b);
	position = find_position(data->b, max);
	if (position <= size / 2)
	{
		while (position--)
			rb(data);
	}
	else
	{
		while (position++ < size)
			rrb(data);
	}
}

static void	push_chunk(t_data *data, int start, int end)
{
	int	pushed;
	int	total;
	int	x;

	total = end - start;
	pushed = 0;
	while (pushed < total)
	{
		x = *(int *)data->a->content;
		if (x >= start && x < end)
		{
			pb(data);
			pushed++;
			if (x < start + (total / 2))
				rb(data);
		}
		else
			ra(data);
	}
}

void	chunk_sort(t_data *data)
{
	int	size;
	int	chunks;
	int	chunk_size;
	int	start;
	int	end;

	size = ft_lstsize(data->a);
	chunks = 5;
	chunk_size = size / chunks;
	start = 0;
	end = chunk_size;
	while (start < size)
	{
		push_chunk(data, start, end);
		start = end;
		end += chunk_size;
		if (end > size)
			end = size;
	}
	while (data->b)
	{
		bring_max_to_top(data);
		pa(data);
	}
}
