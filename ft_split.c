/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:41:17 by sejeon            #+#    #+#             */
/*   Updated: 2022/01/07 17:42:40 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	t_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len++;
			while (*s != c)
				s++;
		}
	}
	return (len);
}

static char	**free_malloc(char **ret)
{
	int	i;

	i = 0;
	while (!ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

static char	*cp_word(char const *s, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == 0)
		return (0);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		st;

	i = 0;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (t_len(s, c) + 1));
	if (arr == 0)
		return (0);
	while (s[i] != '\0' && j < t_len(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		st = i;
		while (s[i] && s[i] != c)
			i++;
		if (cp_word(s + st, i - st) == 0)
			free_malloc(arr);
		arr[j++] = cp_word(s + st, i - st);
	}
	arr[j] = 0;
	return (arr);
}
