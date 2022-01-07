/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:58:22 by sejeon            #+#    #+#             */
/*   Updated: 2022/01/07 16:14:48 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tlen(int n)
{
	int		len;
	long	num;

	len = 0;
	num = n;
	if (n <= 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*res;
	long long	num;
	int			len;

	len = ft_tlen(n);
	num = n;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == 0)
		return (0);
	if (num < 0)
	{
		res[0] = '-';
		num *= -1;
	}
	res[len--] = '\0';
	if (num == 0)
		res[0] = '0';
	while (num)
	{
		res[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (res);
}
