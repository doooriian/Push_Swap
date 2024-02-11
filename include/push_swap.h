/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:56:58 by dley              #+#    #+#             */
/*   Updated: 2024/02/11 18:07:25 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					nbr;
	int					current_position;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

void			free_new_argv(char **new_argv);
void			free_stack(t_stack_node **stack);
void			free_error(t_stack_node **stack_a, char **argv, bool argc_is_2);
int				error_syntax(char *str_nbr);
int				error_repetition(t_stack_node *stack_a, int nbr);

void			init_stack_a(t_stack_node **a, char **argv, bool argc_is_2);
char			**ft_split(char const *s, char c);

void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			set_current_position(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);

int				stack_len(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

#endif