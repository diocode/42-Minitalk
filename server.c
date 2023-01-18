/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:06:50 by digoncal          #+#    #+#             */
/*   Updated: 2023/01/18 18:49:56 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int signal)
{
	static char	c;
	static int	bits;

	if (!c)
		c = 0;
	if (!bits)
		bits = 0;
	if (signal == SIGUSR1)
		c |= 1 << (7 - bits);
	if (signal == SIGUSR2)
		c &= ~(1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		write (1, &c, 1);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	signal;

	pid = getpid();
	if (pid == -1)
	{
		ft_printf("\033[1;31mInvalid PID\033[0m\n");
		exit(1);
	}
	ft_printf("PID: %d\n", pid);
	signal.sa_handler = &action;
	signal.sa_flags = 0;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
}
