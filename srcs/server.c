#include "../includes/minitalk.h"

void receive_sig_char(int signal)
{
	static int i = 0;
	static unsigned char	c = 0;

	c |= (signal - 30) << i++;
	// Il faudra envoyer par ici l'ack au client
	// mais comment recup le pid du client ?
	if (i > 7)
	{
		write(1, &c, sizeof(c));
		c = 0;
		i = 0;
	}
//	usleep(250);
	//if (signal == SIGUSR1 || signal == SIGUSR2)
//	{
		//kill(-1, SIGUSR1);
	//	usleep(100);
//	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	signal(SIGUSR1, receive_sig_char);
	signal(SIGUSR2, receive_sig_char);
	printf("pid: %d\n", pid);
	while (1)
		pause();
	return (0);
}
