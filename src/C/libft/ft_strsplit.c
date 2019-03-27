/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:22:15 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/12/06 16:52:28 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_count(const char *s, char c)
{
	size_t	begin;
	size_t	end;
	size_t	counter;

	counter = 0;
	begin = 0;
	while (s[begin])
	{
		if (s[begin] != c)
		{
			end = begin;
			while (s[end] && s[end] != c)
				++end;
			++counter;
			begin = end - 1;
		}
		++begin;
	}
	return (counter);
}

static void		free_all(char **result)
{
	size_t	i;

	if (!result)
		return ;
	i = 0;
	while (result[i])
	{
		free(result[i]);
		++i;
	}
	free(result);
	*result = NULL;
}

static int		add_words(char **result, const char *s, char c)
{
	size_t	begin;
	size_t	end;
	size_t	counter;

	counter = 0;
	begin = 0;
	while (s[begin])
	{
		if (s[begin] != c)
		{
			end = begin;
			while (s[end] && s[end] != c)
				++end;
			if (!(result[counter] = ft_strnew(end - begin)))
			{
				free_all(result);
				return (-1);
			}
			ft_strncpy(result[counter], s + begin, end - begin);
			++counter;
			begin = end - 1;
		}
		++begin;
	}
	return (0);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	if (!(words = ft_memalloc(sizeof(char *) * (get_word_count(s, c) + 1))))
		return (NULL);
	if (add_words(words, s, c) == -1)
		return (NULL);
	return (words);
}
