/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:58:22 by sejeon            #+#    #+#             */
/*   Updated: 2021/12/29 20:25:12 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	long long	num;
	int			len;

	len = ft_tlen(n);
	num = n;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == 0)
		return (0);
	if (num < 0)
		res[0] = '-';
	if (num == 0)
		res[0] = '0';
	res[len--] = 0;
	while (num)
	{
		res[len--] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}
