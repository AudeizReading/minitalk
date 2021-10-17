#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

# include <stdio.h>
int		ft_atoi(const char *nptr);
size_t	ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
#endif
