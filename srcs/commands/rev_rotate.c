/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:32:59 by dley              #+#    #+#             */
/*   Updated: 2024/02/08 13:49:40 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*last_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	tmp = last_node;
	last_node = last_node->prev;
	last_node->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}

void	rra(t_stack_node **a, bool check)
{
	rev_rotate(a);
	if (!check)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool check)
{
	rev_rotate(b);
	if (!check)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool check)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!check)
		write(1, "rrr\n", 4);
}
