#include "../includes/minitalk.h"

void	send_sig_null_char(int pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
		kill(pid, SIGUSR1);
	printf("%d\n", i);
}

void	send_sig_char(unsigned char *str, int pid)
{
	unsigned long	i;

	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			if (*str >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i++;
			usleep(500);
		}
		str++;
	}
//	printf("i = %lu\n", i);
	send_sig_null_char(pid);
}

void	receive_ack(int signal)
{
	static int i = 0;

	i++;
	if (signal == SIGUSR1/* && i == nbc*/)
		ft_putstr("Ack receipt\n");
	ft_putnbr(i);
	ft_putstr("\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_handler = receive_ack;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc == 3)
	{
		send_sig_char((unsigned char *)argv[2], ft_atoi(argv[1]));
		return (0);
	}
	return (EXIT_FAILURE);
}
