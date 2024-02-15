/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:07:11 by dley              #+#    #+#             */
/*   Updated: 2024/02/15 01:32:48 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>	

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			**new_argv;

	stack_a = NULL;
	stack_b = NULL;
	new_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		new_argv = ft_split(argv[1], ' ');
	if (argc == 2)
		init_stack_a(&stack_a, new_argv, true);
	else
		init_stack_a(&stack_a, argv + 1, false);
	if (!is_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a, false);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
}
