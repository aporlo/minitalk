/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 03:13:51 by lsomrat           #+#    #+#             */
/*   Updated: 2022/09/14 17:32:42 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		check;

	check = 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		check = 0;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = n / (-1);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = (n % 10) + '0';
	if (check)
		write(fd, &c, 1);
}
