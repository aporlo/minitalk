/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:28:36 by lsomrat           #+#    #+#             */
/*   Updated: 2022/09/14 17:44:06 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	acknowledg_handler(int sig);
void		send_binary(int pid, unsigned char byte);
void		handler(char *pid, char *str);

int	main(int argc, char **argv)
{
	signal(SIGUSR1, acknowledg_handler);
	if (argc != 3)
		exit(0);
	handler(argv[1], argv[2]);
	return (0);
}

static void	acknowledg_handler(int sig)
{
	(void)sig;
	if (sig == SIGUSR1)
		write(1, "1", 1);
}

void	send_binary(int pid, unsigned char byte)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (!(byte & (1 << i--)))
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(500);
	}
}

void	handler(char *pid, char *str)
{
	int	process_id;

	process_id = ft_atoi(pid);
	while (*str)
	{
		send_binary(process_id, *str);
		++str;
	}
	send_binary(process_id, *str);
}
