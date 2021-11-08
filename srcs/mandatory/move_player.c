/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:12:05 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/08 17:40:17 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_info *info, int keycode)
{
	if (check_end(keycode, info))
		print_end("Bravo!\n", 7); // A modifier par end screen
	if (check_coin(keycode, info))
	{
		(info->coins)--;
		if (info->coins == 0)
			draw_end2(info, (info->exit_x), (info->exit_y)); // modif 3
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
}

int	deal_key(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		move_player(info, keycode);
	return (0);
}
