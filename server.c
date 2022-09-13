#include "minitalk.h"

// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	c;
// 	int				check;

// 	check = 1;
// 	if (n == -2147483648)
// 	{
// 		write(fd, "-2147483648", 11);
// 		check = 0;
// 	}
// 	else if (n < 0)
// 	{
// 		write(fd, "-", 1);
// 		n = n / (-1);
// 	}
// 	if (n > 9)
// 	{
// 		ft_putnbr_fd(n / 10, fd);
// 	}
// 	c = (n % 10) + '0';
// 	if (check)
// 	{
// 		write(fd, &c, 1);
// 	}
// }

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	handlersig(int signum, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	static struct sig_character		chr = {0,7};
	
	if (signum == SIGUSR2)
		chr.c += (1 << chr.bit);
	chr.bit--;
	if (chr.bit == -1)
	{
		ft_putchar_fd(chr.c, 1);
		chr.c = 0;
		chr.bit = 7;
		if (signum == SIGUSR1)
			kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction		action; 
	pid_t	process_id;
	
	process_id = getpid();
	write(1, "pid: ", 5);
	ft_putnbr_fd(process_id, 1);
	write(1, "\n", 1);
	sigemptyset(&action.sa_mask);
	action.sa_sigaction = handlersig;
	action.sa_flags = SA_SIGINFO;
	sigaction  (SIGUSR1, &action, NULL);
	sigaction (SIGUSR2, &action, NULL);
	while(1)
	{
		pause();
	}
	return (0);
}