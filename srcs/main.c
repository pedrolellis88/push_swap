/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:44:20 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/12/02 16:16:17 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **v)
{
	t_data	data;
	int		*array;

	if (c < 2)
		exit(1);
	data.a = NULL;
	data.b = NULL;
	if (parse_args(v, &data.a) == 0)
		error_and_exit(&data);
	if (is_doubled(data.a) == 0)
		error_and_exit(&data);
	array = array_with_content(data.a, ft_lstsize(data.a));
	if (!array)
		error_and_exit(&data);
	index_list(data.a, array, ft_lstsize(data.a));
	free(array);
	if (is_list_sorted(data.a))
	{
		ft_lstclear(&data.a, free);
		return (0);
	}
	checker(&data);
	ft_lstclear(&data.a, free);
	ft_lstclear(&data.b, free);
	return (0);
}
