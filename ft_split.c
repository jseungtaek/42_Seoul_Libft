/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:41:17 by sejeon            #+#    #+#             */
/*   Updated: 2022/01/07 21:44:05 by sejeon           ###   ########.fr       */
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

static int	free_malloc(char **ret, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (0);
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
	word[i] = '\0';
	return (word);
}

static void	cp_split(char const *s, char c, char **arr)
{
	int	st;
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		st = i;
		while (s[i] && s[i] != c)
			i++;
		arr[len] = cp_word(s + st, i - st);
		if (arr[len] == 0)
		{
			free_malloc(arr);
			return ;
		}
		len++;
	}
	arr[len] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (t_len(s, c) + 1));
	if (arr == 0)
		return (0);
	cp_split(s, c, arr);
	return (arr);
}
