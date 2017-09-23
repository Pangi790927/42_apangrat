/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 22:57:26 by apangrat          #+#    #+#             */
/*   Updated: 2017/09/21 22:09:10 by apangrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_separator(char c, char *separator)
{
	while (*separator)
		if (c == *(separator++))
			return (1);
	return (0);
}

int		ft_strlen_sep(char *str, char *separators)
{
	int len;

	len = 0;
	while (str[len])
	{
		if (ft_is_separator(str[len], separators))
			return (len);
		len++;
	}
	return (len);
}

int		ft_split_whitespaces_count(char *str, char *separators)
{
	int		count;
	int		next_word_len;
	char	*current_word;

	count = 0;
	current_word = str;
	while (*current_word)
	{
		next_word_len = ft_strlen_sep(current_word, separators);
		if (next_word_len == 0)
			current_word++;
		else
		{
			current_word += next_word_len;
			count++;
		}
	}
	return (count);
}

char	**ft_split_whitespaces(char *str)
{
	int		count;
	char	**table;
	int		it;
	int		str_it;

	count = ft_split_whitespaces_count(str, " \t\n");
	table = (char **)malloc((count + 1) * sizeof(char *));
	it = 0;
	while (it < count)
	{
		while (ft_is_separator(*str, " \t\n"))
			str++;
		table[it] = (char*)malloc(ft_strlen_sep(str, " \t\n") * sizeof(char));
		str_it = 0;
		while (!ft_is_separator(str[str_it], "\t\n "))
		{
			table[it][str_it] = str[str_it];
			str_it++;
		}
		str += str_it;
		table[it][str_it] = '\0';
		it++;
	}
	table[it] = 0;
	return (table);
}
