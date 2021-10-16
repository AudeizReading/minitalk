#include "../includes/minitalk.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
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
			usleep(300);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	char	*test = "😎";
	if (argc > 1 && argc < 4)
	{
		send_sig_char((unsigned char *)argv[2], atoi(argv[1]));
		return (0);
	}
	return (EXIT_FAILURE);
}
