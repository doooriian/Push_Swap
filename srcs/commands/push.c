/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:32:37 by dley              #+#    #+#             */
/*   Updated: 2024/02/07 16:46:20 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b, bool check)
{
	push(stack_a, stack_b);
	if (check)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b, bool check)
{
	push(stack_b, stack_a);
	if (check)
		write(1, "pb\n", 3);
}
