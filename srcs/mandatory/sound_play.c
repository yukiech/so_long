/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:05:46 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/12 11:25:53 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sound_music(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execlp("afplay", "afplay", "-v", "0.2", "sound/isaac.mp3", NULL);
	}
}

void	sound_coin(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execlp("afplay", "afplay", "sound/coin.mp3", NULL);
}

void	sound_door(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execlp("afplay", "afplay", "-v", "2", "sound/door.mp3", NULL);
}

void	sound_death(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execlp("afplay", "afplay", "-v", "1", "sound/mort.wav", NULL);
}

void	sound_kill(void)
{
	const char	*command;

	command = "killall afplay";
	system(command);
}
