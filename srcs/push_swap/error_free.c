/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:29:11 by dley              #+#    #+#             */
/*   Updated: 2024/02/14 14:16:09 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_new_argv(char **new_argv)
{
	int	i;

	i = 0;
	if (!new_argv || !*new_argv)
		return ;
	while (new_argv[i])
	{
		free(new_argv[i]);
		i++;
	}
	free(new_argv);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_error(t_stack_node **stack_a, char **argv, bool argc_is_2)
{
	free_stack(stack_a);
	if (argc_is_2)
		free(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *str_nbr)
{
	if (!str_nbr || ((*str_nbr != '+' || *str_nbr != '-')
			&& (*str_nbr < '0' && *str_nbr > '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-')
		&& (*(str_nbr + 1) < '0' || *(str_nbr + 1) > '9'))
		return (1);
	if (*str_nbr == '+' || *str_nbr == '-')
		str_nbr++;
	while (*str_nbr)
	{
		if (*str_nbr < '0' || *str_nbr > '9')
			return (1);
		str_nbr++;
	}
	return (0);
}

int	error_repetition(t_stack_node *stack_a, int nbr)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->nbr == nbr)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
