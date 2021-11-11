/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:12:05 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/11 19:36:09 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_info *info, int keycode)
{
	if (check_end(keycode, info))
	{
		info->ended = 2;
		mlx_put_image_to_window(info->mlx, info->win, info->img.winscreen,
				0, 0);
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
	draw_player(info, keycode);
	if (info->ended == 2)
		mlx_put_image_to_window(info->mlx, info->win, info->img.winscreen,
                0, 0);
}

void	move_ennemi(t_info *info)
{
	if ((info->ennemi.move) > 3)
		info->ennemi.move = -4;
	if (info->map[info->ennemi.y][info->ennemi.x] == 'P')
	{
		sound_death();
		endscreen(info, 0, 0);
		info->ended = 1;
	}
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
		endscreen(info, 0, 0);
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
		if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
			|| keycode == KEY_D)
		{
			move_player(info, keycode);
			if (info->ennemi.exist == 1)
				move_ennemi(info);
			draw_scoreboard(info, 10, 10);
		}
	}
	else if (info->ended == 1)
	{
		if (keycode == KEY_B)
			ft_close(info);
		else if (keycode == KEY_A)
		{
			mlx_destroy_window(info->mlx, info->win);
			sound_kill();
			game(info->argc, info->argv);
		}
	}
	else if (info->ended == 2)
	{
		if (keycode == KEY_B)
            ft_close(info);
        else if (keycode == KEY_A)
        {
            mlx_destroy_window(info->mlx, info->win);
            game(info->argc, info->argv);
        }
	}
	return (0);
}
