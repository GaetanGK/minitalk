/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:56:04 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/14 15:56:06 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_msg_print(int bit, t_signal *g_bites)
{
	if (bit == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	g_bites->byte += bit << g_bites->size;
	g_bites->size++;
	if (g_bites->size == 8)
	{
		ft_putchar_fd(g_bites->byte, 1);
		g_bites->byte = 0;
		g_bites->size = 0;
	}
}

void	handler(int num, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	g_bites.pid = info->si_pid;
	ft_msg_print(num, &g_bites);
}

int	main(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	g_bites.size = 0;
	g_bites.byte = 0;
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
