/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:49:55 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/12/08 11:49:59 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-(unsigned int)n);
	return ((unsigned int)n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
		ft_putchar_fd('-', fd);
	num = ft_abs(n);
	if (num >= 10)
	{
		ft_putnbr_fd((int)(num / 10), fd);
		ft_putnbr_fd((int)(num % 10), fd);
	}
	else
		ft_putchar_fd((char)(num % 10 + '0'), fd);
}
