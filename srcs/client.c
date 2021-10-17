#include "../includes/minitalk.h"

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
}

void	receive_ack(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr("Ack receipt\n");
	pause();
}

int	main(int argc, char **argv)
{
	if (argc > 1 && argc < 4)
	{
		send_sig_char((unsigned char *)argv[2], ft_atoi(argv[1]));
		//signal(SIGUSR1, receive_ack);
		//usleep(500);
		return (0);
	}
	return (EXIT_FAILURE);
}
