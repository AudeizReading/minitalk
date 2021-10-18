#include "../includes/minitalk.h"

void receive_sig_char(int signal, siginfo_t *info, void *context)
//void receive_sig_char(int signal)
{
	(void)info;
	(void)context;
	static int i = 0;
	static unsigned char	c = 0;

	c |= (signal - 30) << i++;
	if (i > 7)
	{
		ft_putchar(c);
		c = 0;
		i = 0;
	}
//	usleep(250);
	kill(info->si_pid, SIGUSR1);
	//if (!kill(info->si_pid, 0))
	//	ft_putstr("prout\n");
}

int	main(void)
{
	pid_t	pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = receive_sig_char;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	//signal(SIGUSR1, receive_sig_char);
	//signal(SIGUSR2, receive_sig_char);
	ft_putstr("pid: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
