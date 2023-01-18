/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:55:47 by digoncal          #+#    #+#             */
/*   Updated: 2023/01/18 18:53:47 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_msg(int pid, char *msg)
{
	char 	c;
	int		bit;

	while (*msg)
	{
		c = *msg;
		bit = sizeof(char) * 8;
		while (bit--)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		msg++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		exit(1);
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0)) 
	{
		ft_printf("\033[1;31mInvalid PID\033[0m\n");
		exit(1);
	}
	send_msg(pid, "\033[1;32mClient: \033[0m");
	send_msg(pid, argv[2]);
	send_msg(pid, "\n");
}
