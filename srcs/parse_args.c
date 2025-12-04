/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:16:02 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/26 12:58:11 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	count_numbers(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

static	void	free_split(char	**s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}	

int	parse_args(char **v, t_list **a)
{
	char	**splited;
	char	*temp1;
	char	*temp2;
	int		i;

	i = 0;
	temp2 = ft_strdup("");
	if (!temp2)
		return (0);
	while (v[++i])
	{
		temp1 = ft_strjoin(temp2, v[i]);
		free(temp2);
		temp2 = ft_strjoin(temp1, " ");
		free(temp1);
	}
	splited = ft_split(temp2, ' ');
	free(temp2);
	if (!splited)
		return (0);
	*a = create_head_with_ints(count_numbers(splited), splited);
	free_split(splited);
	if (!*a)
		return (0);
	return (1);
}
/*void    print(void *p)
{
        ft_printf("%i\n", *(int *)p);
}

int     main(int c, char **v)
{
	t_list	*a = NULL;

	parse_args(c, v, &a);
	ft_lstiter(a, print);
}*/
