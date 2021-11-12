/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:14:46 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/12 13:37:16 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_info *info)
{
	(void)info;
	sound_kill();
	exit(0);
}

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'M')
		return (1);
	return (0);
}

void	print_end(char *str, int len)
{
	write(1, str, len);
	exit(1);
}

void	endscreen(t_info *info, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->img.endscreen,
		x, y);
}

void	death(t_info *info)
{
	sound_death();
	endscreen(info, 0, 0);
	info->ended = 1;
}
