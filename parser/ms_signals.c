/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:34:26 by aiturria          #+#    #+#             */
/*   Updated: 2024/07/18 14:33:31 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <signal.h>

void	ms_interactive(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ms_noninteractive(int signum)
{
	(void)signum;
	g_signal = 1;
	write(1, "\n", 1);
	rl_on_new_line();
}

void	ms_setsignals1(void)
{
	struct sigaction	signal;

	ft_memset(&signal, 0, sizeof(signal));
	signal.sa_handler = &ms_interactive;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGINT, &signal, NULL);
	signal.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &signal, NULL);
}

void	ms_setsignals2(void)
{
	struct sigaction	signal;

	ft_memset(&signal, 0, sizeof(signal));
	signal.sa_handler = &ms_noninteractive;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGINT, &signal, NULL);
	signal.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &signal, NULL);
}
