/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:03:04 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/05/01 19:37:13 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	wc;

	wc = 0;
	while (*s)
	{
		if (*s != c)
		{
			wc++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (wc);
}

static char	**ft_alloc_table(int size)
{
	char	**table;

	table = (char **)malloc((size + 1) * sizeof(char *));
	if (!table)
		return (NULL);
	ft_bzero(table, (size + 1) * sizeof(char *));
	return (table);
}

static char	*ft_worddup(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = ft_substr(s, 0, i);
	if (!word)
		return (NULL);
	return (word);
}

static char	**ft_fill_table(char **table, char const *s, char c, int wc)
{
	int	i;

	i = 0;
	while (*s && i < wc)
	{
		if (*s != c)
		{
			table[i] = ft_worddup(s, c);
			if (!table[i])
				return (NULL);
			i++;
			s += ft_strlen(table[i - 1]);
		}
		else
			s++;
	}
	return (table);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	int		wc;

	if (!s)
		return (NULL);
	wc = ft_count_words(s, c);
	table = ft_alloc_table(wc);
	if (!table)
		return (NULL);
	if (!ft_fill_table(table, s, c, wc))
	{
		while (wc >= 0)
			free(table[wc--]);
		free(table);
		return (NULL);
	}
	return (table);
}
