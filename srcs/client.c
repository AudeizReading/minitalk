#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	(void)argc;
	(void)argv;

	pid = getpid();
	printf("pid: %d\n", pid);
	return (0);
}
