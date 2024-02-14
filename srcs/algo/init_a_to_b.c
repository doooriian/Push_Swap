/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:35:43 by dley              #+#    #+#             */
/*   Updated: 2024/02/14 16:17:10 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int		i;
	int		median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_target;

	while (a)
	{
		best_target = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr < best_target)
			{
				best_target = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_target == LONG_MIN)
			a->target_node = find_min(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int		len_a;
	int		len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->current_position;
		if (!(a->above_median))
			a->push_cost = len_a - (a->current_position);
		printf("%d\n", a->target_node->nbr);
		if (a->target_node->above_median)
		{
			printf("la\n");
			a->push_cost += a->target_node->current_position;
		}
		else
		{	
			printf("la\n");
			a->push_cost += len_b - (a->target_node->current_position);
		}
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	t_stack_node	*best_cost_node;
	long			best_cost;

	if (!stack)
		return ;
	best_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < best_cost)
		{
			best_cost = stack->push_cost;
			best_cost_node = stack;
		}
		stack = stack->next;
	}
	best_cost_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheapest(a);
}
