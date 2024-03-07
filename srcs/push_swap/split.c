/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:43:58 by dley              #+#    #+#             */
/*   Updated: 2024/03/07 11:27:59 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	count_words(char const *s, char c)
{
	int		count;
	bool	in_word;

	count = 0;
	while (*s)
	{
		in_word = false;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			if (!in_word)
			{
				count++;
				in_word = true;
			}
			s++;
		}
	}
	return (count);
}

static char	*get_next_word(char const *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (s[cursor] == c)
		cursor++;
	while (s[cursor + len] && s[cursor + len] != c)
		len++;
	next_word = malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	while (s[cursor] && s[cursor] != c)
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		words_count;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	tab = malloc(sizeof(char *) * (words_count + 1));
	if (!tab)
		return (NULL);
	while (words_count > 0)
	{
		tab[i] = get_next_word(s, c);
		i++;
		words_count--;
	}
	tab[i] = NULL;
	return (tab);
}
