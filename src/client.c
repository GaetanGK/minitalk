/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <jfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:19:09 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/14 14:31:11 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_byte_by_byte(int pid, char byte)
{
	int		bit;
	int		res;
	int		i;

	i = 0;
	while (i < 8)
	{
		bit = (byte >> i) & 1;
		if (bit == 0)
			res = kill(pid, SIGUSR1);
		else
			res = kill(pid, SIGUSR2);
		i++;
		if (res == -1)
	{
		ft_putstr_fd("Error Pid \n", 1);
		exit(1);
	}
	usleep(1000);
	}
}

void	ft_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	usleep(50);
	while (msg[i] != '\0')
	{
		ft_byte_by_byte(pid, msg[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		if (argc > 3)
			ft_putstr_fd("Too much parameters \n", 1);
		if (argc < 3)
			ft_putstr_fd("Missing parameters \n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1)
	{
		ft_putstr_fd("Incorrect Pid \n", 1);
		exit(1);
	}
	ft_msg(pid, argv[2]);
	ft_putstr_fd("Message successfully delivered! \n", 1);
	return (0);
}
