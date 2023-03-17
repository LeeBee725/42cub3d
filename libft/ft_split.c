/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:13:10 by junhelee          #+#    #+#             */
/*   Updated: 2022/05/11 09:10:10 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words_num;
	size_t	i;
	int		flag;

	i = 0;
	if (s == NULL || !s[i])
		return (0);
	words_num = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] != c && flag == 1)
		{
			flag = 0;
			++words_num;
		}
		else if (s[i] == c)
			flag = 1;
		++i;
	}
	return (words_num);
}

static char	*word_dup(char const *s, size_t start, size_t end)
{
	char	*word;

	if (s == NULL)
		return (NULL);
	word = (char *)ft_calloc(end - start + 1, sizeof(char));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, s + start, end - start + 1);
	return (word);
}

static void	free_all(char ***result)
{
	size_t	len;

	len = 0;
	while ((*result)[len] != NULL)
	{
		free((*result)[len]);
		++len;
	}
	free(*result);
	*result = NULL;
}

static void	set_word_in_words(char ***words, char const *s, char c)
{
	size_t	word_pos;
	size_t	start;
	size_t	end;

	word_pos = 0;
	start = 0;
	while (s[start] == c)
		++start;
	end = start;
	while (end <= ft_strlen(s))
	{
		if (s[end] == c || (s[end] == '\0' && start != end))
		{
			(*words)[word_pos] = word_dup(s, start, end);
			if ((*words)[word_pos++] == NULL)
			{
				free_all(words);
				return ;
			}
			while (s[end] == c && s[end + 1] == c)
				++end;
			start = end + 1;
		}
		++end;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	words = (char **)ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!words)
		return (NULL);
	if (!s || count_words(s, c) == 0)
		return (words);
	set_word_in_words(&words, s, c);
	return (words);
}
