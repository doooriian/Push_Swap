/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:14:41 by dley              #+#    #+#             */
/*   Updated: 2024/02/02 15:17:57 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int		size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

