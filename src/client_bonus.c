/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:27:08 by digoncal          #+#    #+#             */
/*   Updated: 2023/01/19 10:08:33 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	sig_msg(int pid, char *msg)
{
	char	c;
	int		bit;

	while (*msg)
	{
		c = *msg++;
		bit = sizeof(char) * 8;
		while (bit--)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

static void	confirm(int s)
{
	(void)s;
	ft_printf("\033[1;32mMessage Received\033[0m\n");
}

static void	end_msg_signal(pid_t pid)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		exit(1);
	signal(SIGUSR1, confirm);
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0))
	{
		ft_printf("\033[1;31mInvalid PID\033[0m\n");
		exit(1);
	}
	sig_msg(pid, "\033[1;32mClient: \033[0m");
	sig_msg(pid, argv[2]);
	sig_msg(pid, "\n");
	end_msg_signal(pid);
	while (1)
		pause();
}
