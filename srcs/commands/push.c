/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:32:37 by dley              #+#    #+#             */
/*   Updated: 2024/02/15 00:44:30 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (!(*dst))
	{
		*dst = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		tmp->next->prev = tmp;
		*dst = tmp;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool check)
{
	push(a, b);
	if (!check)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b, bool check)
{
	push(b, a);
	if (!check)
		write(1, "pb\n", 3);
}
