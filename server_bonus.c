/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:26:56 by digoncal          #+#    #+#             */
/*   Updated: 2023/01/18 18:46:39 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void action(int s, siginfo_t *info, void *content)
{
	static char	c;
	static int	bit;

	(void)content;
	if (!c)
		c = 0;
	if (!bit)
		bit = 0;
	if (s == SIGUSR1)
		c |= 1 << (7 - bit);
	if (s == SIGUSR2)
		c &= ~(1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (!c)
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &c, 1);
		c = 0;
		bit = 0;
	}
	
}

int main(void)
{
	pid_t	pid;
	struct	sigaction sig;

	pid = getpid();
	if (pid == -1)
	{
		ft_printf("\033[1;31mInvalid PID\033[0m\n");
		exit(1);
	}
	ft_printf("PID: %d\n", pid);
	sig.sa_sigaction = &action;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
