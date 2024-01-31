/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:43:58 by dley              #+#    #+#             */
/*   Updated: 2024/01/31 14:36:26 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

char	*copy_str(char const *s, char c)
{
	char	*copy;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_fill_tab(char **tab, char const *s, char c, int len)
{
	int	i;

	i = 0;
	while (i != len)
	{
		while (*s && *s == c)
			s++;
		tab[i] = copy_str(s, c);
		if (!tab[i])
		{
			while (i > 0)
				free(tab[--i]);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**split(char const *s, char c)
{
	char	**tab;
	int		len;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	tab = malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	return (ft_fill_tab(tab, s, c, len));
}
