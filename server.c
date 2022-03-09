/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:21:31 by naapikya          #+#    #+#             */
/*   Updated: 2021/10/19 15:06:45 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	g_msg;

void	ft_printletter(int signal)
{
	char	a;

	if (signal == SIGUSR1)
	{
		g_msg.c = g_msg.c << 1;
		g_msg.c++;
	}
	else if (signal == SIGUSR2)
	{
		g_msg.c = g_msg.c << 1;
	}
	g_msg.count++;
	if (g_msg.count == 8)
	{
		a = (char)g_msg.c;
		write(1, &a, 1);
		g_msg.count = 0;
	}
}

int	main(void)
{
	int	pid;

	g_msg.c = 0;
	g_msg.count = 0;
	g_msg.print = 0;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, ft_printletter);
		signal(SIGUSR2, ft_printletter);
	}
}
