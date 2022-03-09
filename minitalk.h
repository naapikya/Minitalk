/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:52:02 by naapikya          #+#    #+#             */
/*   Updated: 2021/10/19 13:55:02 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

void	ft_putnbr(int nb);
int		ft_atoi(const char *str);
void	ft_printLetter(int signal);
typedef struct s_message
{
	int	c;
	int	print;
	int	count;
}	t_message;

#endif
