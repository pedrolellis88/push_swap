/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_three_five_sort_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:28:01 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/12/02 15:29:04 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_data *data)
{
	int	size;

	if (is_list_sorted(data->a) == 1)
		return ;
	size = ft_lstsize(data->a);
	if (size == 2)
		sort_two(data);
	else if (size == 3)
		sort_three(data);
	else if (size == 4)
		sort_four(data);
	else if (size == 5)
		sort_five(data);
	else if (size <= 100)
		chunk_sort(data);
	else
		radix(data);
}

void	sort_two(t_data *data)
{
	if (*(int *)data->a->content > *(int *)data->a->next->content)
		sa(data);
}

void	sort_three(t_data *data)
{
	int	x;
	int	y;
	int	z;

	x = *(int *)data->a->content;
	y = *(int *)data->a->next->content;
	z = *(int *)data->a->next->next->content;
	if (x > y && y > z)
	{
		sa(data);
		rra(data);
	}
	else if (x > y && x > z && y < z)
		ra(data);
	else if (x < y && x > z)
		rra(data);
	else if (x > y && x < z)
		sa(data);
	else if (x < y && y > z)
	{
		sa(data);
		ra(data);
	}
}

void	sort_four(t_data *data)
{
	int	smallest;

	smallest = find_smallest(data->a);
	push_smallest_to_top(&data->a, smallest, data);
	pb(data);
	sort_three(data);
	pa(data);
}

void	sort_five(t_data *data)
{
	int	smallest;
	int	second_smallest;

	smallest = find_smallest(data->a);
	push_smallest_to_top(&data->a, smallest, data);
	if (is_list_sorted(data->a) == 1)
		return ;
	pb(data);
	second_smallest = find_smallest(data->a);
	push_smallest_to_top(&data->a, second_smallest, data);
	if (*(int *)data->b->content < *(int *)data->a->content
		&& is_list_sorted(data->a) == 1)
	{
		pa(data);
		return ;
	}
	pb(data);
	sort_three(data);
	pa(data);
	pa(data);
}
