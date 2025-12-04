/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:36:00 by pdiniz-l          #+#    #+#             */
/*   Updated: 2025/11/28 14:23:41 by pdiniz-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft_applier/libft.h"

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
}			t_data;

/* Files with 1 function */

t_list	*create_head_with_ints(int c, char **v);
int		parse_args(char **v, t_list **a);
void	error_and_exit(t_data *data);
int		is_str_valid(char *str);
int		is_doubled(t_list *a);
int		safe_atoi(const char *s, int *out);
int		is_list_sorted(t_list *a);

/* swap_utils.c */

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

/* push_utils.c */

void	pa(t_data *data);
void	pb(t_data *data);

/* rotate_utils.c */

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

/* reverse_rotate.c */

void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

/* two_three_five_sort_utils.c */

void	checker(t_data *data);
void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);
/*** file for sort_five (sort_five_especific_utils.c) ***/
int		find_position(t_list *a, int i);
int		find_smallest(t_list *a);
void	push_smallest_to_top(t_list **a, int i, t_data *data);

/* indexing.c */
/* 1 */
int		*array_with_content(t_list *a, unsigned int size);
void	index_list(t_list *a, int *sorted_array, unsigned int size);
/* 2 */
int		find_max_index(t_list *a);
int		max_bits(t_list *a);
void	radix(t_data *data);

/* chunk_sort */

void	chunk_sort(t_data *data);
#endif
