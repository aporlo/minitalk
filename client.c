/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:28:36 by lsomrat           #+#    #+#             */
/*   Updated: 2022/08/25 16:28:44 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
void    handler(char *pid, char *str);

int main(int argc, char **argv)
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
}

// int	ft_atoi(const char *s)
// {
// 	unsigned int	n;
// 	int				i;
// 	int				sign;

// 	i = 0;
// 	n = 0;
// 	sign = 1;
// 	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
// 		|| s[i] == '\f' || s[i] == '\v' || s[i] == '\r')
// 		i++;
// 	if (s[i] == '-')
// 		sign = -1;
// 	if (s[i] == '-' || s[i] == '+')
// 		i++;
// 	while (s[i] >= '0' && s[i] <= '9')
// 	{
// 		n = n * 10 + (s[i] - '0');
// 		i++;
// 	}
// 	return ((int)(sign * n));
// }

void    send_binary(int pid, unsigned char byte)
{
    int         i;

    i = 7;
    while(i >= 0)
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

void    handler(char *pid, char *str)
{
    int     process_id;

    process_id = ft_atoi(pid);
    while (*str)
    {
        send_binary(process_id, *str);
        ++str;
    }
    send_binary(process_id, *str);
}    


// int main(int argc, char **argv)
// {
//     signal(SIGUSR1, acknowledg_handler);
//     if (argc != 3)
//         exit(0);
//     handler(argv[1], argv[2]);
//     return (0);
// }