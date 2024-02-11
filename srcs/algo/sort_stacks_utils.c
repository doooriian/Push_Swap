/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:35:45 by dley              #+#    #+#             */
/*   Updated: 2024/02/11 20:19:47 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node)
{
	while (*b != cheapest_node && *a != cheapest_node->target_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node)
{
	while (*b != cheapest_node && *a != cheapest_node->target_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	push_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
