/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:55:55 by naapikya          #+#    #+#             */
/*   Updated: 2021/10/19 15:05:11 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	g_msg;

void	ft_norm(char *argv2, int pid)
{
	int	bit;
	int	i;

	i = 0;
	while (argv2[i])
	{
		bit = 8;
		g_msg.print = 0;
		while (bit)
		{
			if ((argv2[i] & 128) == 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			argv2[i] = argv2[i] << 1;
			bit--;
			usleep(20);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	ft_norm(argv[2], pid);
	return (0);
}
