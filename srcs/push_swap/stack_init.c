/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:04:57 by dley              #+#    #+#             */
/*   Updated: 2024/02/07 20:05:06 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i] - '0');
	return (nbr * sign);
}

static void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = nbr;
	if (!(*stack))
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	stack_init(t_stack_node **stack_a, char **argv, bool argc_is_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(stack_a, argv, argc_is_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(stack_a, argv, argc_is_2);
		if (error_repetition(*stack_a, (int)nbr))
			free_errors(stack_a, argv, argc_is_2);
		append_node(stack_a, (int)nbr);
		i++;
	}
	if (argc_is_2)
		free_new_argv(argv);
}
