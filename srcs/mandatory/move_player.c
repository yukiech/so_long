/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:12:05 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/12 14:11:44 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_info *info, int keycode)
{
	if (check_end(keycode, info))
	{
		info->ended = 2;
		if (info->ended == 2 && strcmp(info->argv[1], "map/map1.ber") == 0)
			mlx_put_image_to_window(info->mlx, info->win, info->img.winscreen,
				0, 0);
		else
			ft_close(info);
	}
	if (check_coin(keycode, info))
	{
		(info->coins)--;
		sound_coin();
		if (info->coins == 0)
		{
			draw_end2(info, (info->exit_x), (info->exit_y));
			sound_door();
		}
	}
	fonction_trop_longue(info, keycode);
	draw_player(info, keycode);
	if (info->ended == 2 && strcmp(info->argv[1], "map/map1.ber") == 0)
		mlx_put_image_to_window(info->mlx, info->win, info->img.winscreen,
			0, 0);
}

void	fonction_trop_longue(t_info *info, int keycode)
{
	if (!(check_wall(keycode, info)))
	{
		draw_tile(info, info->player.x, info->player.y);
		info->map[info->player.y][info->player.x] = '0';
		if (keycode == KEY_W)
			info->player.y -= 1;
		else if (keycode == KEY_A)
			info->player.x -= 1;
		else if (keycode == KEY_S)
			info->player.y += 1;
		else if (keycode == KEY_D)
			info->player.x += 1;
		info->map[info->player.y][info->player.x] = 'P';
		(info->movement++);
	}
}

void	move_ennemi(t_info *info)
{
	if ((info->ennemi.move) > 3)
		info->ennemi.move = -4;
	if (info->map[info->ennemi.y][info->ennemi.x] == 'P')
		death(info);
	draw_tile(info, info->ennemi.x, info->ennemi.y);
	info->map[info->ennemi.y][info->ennemi.x] = '0';
	if (info->ennemi.move >= 0)
	{
		info->ennemi.x += 1;
		info->ennemi.move += 1;
		draw_ennemi2(info, info->ennemi.x, info->ennemi.y);
	}
	else
	{
		info->ennemi.x -= 1;
		info->ennemi.move += 1;
		draw_ennemi(info, info->ennemi.x, info->ennemi.y);
	}
	if (info->map[info->ennemi.y][info->ennemi.x] == 'P')
		info->ended = 1;
	info->map[info->ennemi.y][info->ennemi.x] = 'M';
	if (info->ended == 1)
		death(info);
}

int	deal_key(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
	{
		sound_kill();
		exit(0);
	}
	if (info->ended == 0)
	{
		deal_key_2(keycode, info);
	}
	else if (info->ended == 1)
	{
		deal_key_3(keycode, info);
	}
	else if (info->ended == 2)
	{
		deal_key_4(keycode, info);
	}
	return (0);
}
