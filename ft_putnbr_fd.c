/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeon <sejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:15:03 by sejeon            #+#    #+#             */
/*   Updated: 2021/12/20 23:03:34 by sejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num[10];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	else if (n == 0)
	{
		num[i] = 0 + '0';
		i++;
	}
	while (n != 0)
	{
		num[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar_fd(num[j++], fd);
	ft_putchar_fd('\n', fd);
}
