/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:28:12 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/12/01 11:05:56 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				temp;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (tab[j] < tab[j - 1])
			{
				temp = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int value, int *array, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	write(2, "Error\n", 6);
	exit(1);
}

int	*array_with_content(t_list *a, unsigned int size)
{
	int				*array;
	unsigned int	i;

	if (size == 0)
		return (NULL);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size && a)
	{
		array[i] = *(int *)a->content;
		a = a->next;
		i++;
	}
	sort_int_tab(array, size);
	return (array);
}

void	index_list(t_list *a, int *sorted_array, unsigned int size)
{
	int	value;
	int	i;
	int	*new_value;

	while (a)
	{
		value = *(int *)a->content;
		i = find_index(value, sorted_array, size);
		new_value = (int *)malloc(sizeof(int));
		if (!new_value)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		*new_value = i;
		free(a->content);
		a->content = new_value;
		a = a->next;
	}
}	
/*
int	main()
{
	int	tab[4] = {40, 10, 30, 90};
	int	i = 0;

	sort_int_tab(tab, 4);
	while (i < 4)
	{
		ft_printf("[%d], ", tab[i]);
		i++;
	}
}
*/				
