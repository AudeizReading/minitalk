#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

# include <stdio.h>
/* utils_bonus.c */
int		ft_atoi(const char *nptr);
size_t	ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

/* server_bonus.c */
void	ft_receive_sig_char(int signal, siginfo_t *info, void *context);
void	ft_show_pid(void);
void	ft_listen_clt_sig(void);

/* client_bonus.c */
void	ft_send_sig_str(unsigned char *str, int pid);
void	ft_receive_ack(int signal);
void	ft_wait_server_ack(void);
#endif
