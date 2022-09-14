/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:18:29 by lsomrat           #+#    #+#             */
/*   Updated: 2022/09/14 18:03:05 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putchar_fd(char c, int fd);
void		handlersig(int signum, siginfo_t *info, void *ucontext);

t_sigcharacter	g_chr = {0, 7};

int	main(void)
{
	struct sigaction		action;
	pid_t					process_id;

	process_id = getpid();
	write(1, "pid: ", 5);
	ft_putnbr_fd(process_id, 1);
	write(1, "\n", 1);
	sigemptyset(&action.sa_mask);
	action.sa_sigaction = handlersig;
	action.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &action, NULL);
	sigaction (SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	handlersig(int signum, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	if (signum == SIGUSR2)
		g_chr.c += (1 << g_chr.bit);
	g_chr.bit--;
	if (g_chr.bit == -1)
	{
		ft_putchar_fd(g_chr.c, 1);
		g_chr.c = 0;
		g_chr.bit = 7;
		if (signum == SIGUSR1)
			kill(info->si_pid, SIGUSR1);
	}
}
