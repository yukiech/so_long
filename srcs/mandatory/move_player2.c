/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:12:05 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/12 13:58:41 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	deal_key_2(int keycode, t_info *info)
{
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
	{
		move_player(info, keycode);
		if (info->ennemi.exist == 1)
			move_ennemi(info);
		draw_scoreboard(info, 10, 10);
	}
}

void	deal_key_3(int keycode, t_info *info)
{
	if (keycode == KEY_B)
		ft_close(info);
	else if (keycode == KEY_A)
	{
		sound_kill();
		mlx_destroy_window(info->mlx, info->win);
		game(info->argc, info->argv);
	}
}

void	deal_key_4(int keycode, t_info *info)
{
	if (keycode == KEY_B)
		ft_close(info);
	else if (keycode == KEY_A)
	{
		sound_kill();
		mlx_destroy_window(info->mlx, info->win);
		game(info->argc, info->argv);
	}
}
