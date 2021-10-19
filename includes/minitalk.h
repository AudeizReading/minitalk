#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

# include <stdio.h>
/* utils.c */
int		ft_atoi(const char *nptr);
size_t	ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

/* server.c */
void	ft_receive_sig_char(int signal);
void	ft_show_pid(void);
void	ft_listen_clt_sig(void);

/* client.c */
void	ft_send_sig_str(unsigned char *str, int pid);
#endif
