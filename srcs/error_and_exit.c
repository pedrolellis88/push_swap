/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:28:01 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/26 12:03:41 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_exit(t_data *data)
{
	if (data != NULL)
	{
		if (data->a)
			ft_lstclear(&data->a, free);
		if (data->b)
			ft_lstclear(&data->b, free);
	}
	write(2, "Error\n", 6);
	exit(1);
}
