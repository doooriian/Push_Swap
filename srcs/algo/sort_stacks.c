/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:29:27 by dley              #+#    #+#             */
/*   Updated: 2024/02/14 15:35:30 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int		len_a;

	len_a = stack_len(*a);
	pb (b, a, false);
	pb (b, a, false);
	while (len_a > 0 && !(is_sorted(*a)))
	{
		init_nodes_a(*a, *b);
		push_a_to_b(a, b);
		len_a--;
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		push_b_to_a(a, b);
	}
	set_current_position(*a);
	min_on_top(a);
}
