#include "../includes/minitalk.h"

void	send_sig_str(unsigned char *str, int pid)
{
	unsigned long		i;

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
			usleep(700);
		}
		str++;
	}
}

void	receive_ack(int signal)
{
	static int			i = 0;

	i++;
	ft_putstr("\tBit Acknowledgment\n");
	if (signal == SIGUSR1 && i == 8)
	{
		ft_putstr("\033[1;45;38mBytes Acknowledgment\033[0m\n");
		i = 0;
	}
	usleep(100);
}

void	ft_wait_server_ack(void)
{
	struct sigaction	sa;

	sa.sa_handler = receive_ack;
	sa.sa_flags = SA_NODEFER;
	sigemptyset(&(sa.sa_mask));
	sigaddset(&(sa.sa_mask), SIGUSR1);
	if (sigaction(SIGUSR1, &sa, NULL))
	{
		ft_putstr("Error with SIGUSR1 or SIGUSR2\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	ft_wait_server_ack();
	if (argc == 3)
	{
		send_sig_str((unsigned char *)argv[2], ft_atoi(argv[1]));
		send_sig_str((unsigned char *)"\0", ft_atoi(argv[1]));
	}
	else
	{
		ft_putstr("\tUsage: ./client [server PID] [string]\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
