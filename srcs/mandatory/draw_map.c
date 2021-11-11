/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:13:46 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/11 15:38:46 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_info *info, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->img.tile,
		x * 50, y * 50);
}

void	draw_wall(t_info *info, int x, int y)
{
	draw_tile(info, x, y);
	mlx_put_image_to_window(info->mlx, info->win, info->img.wall,
		x * 50, y * 50);
}

void	draw_coin(t_info *info, int x, int y)
{
	draw_tile(info, x, y);
	mlx_put_image_to_window(info->mlx, info->win, info->img.coin1,
		x * 50 + 10, y * 50 + 10);
}

void	draw_end(t_info *info, int x, int y)
{
	draw_tile(info, x, y);
	mlx_put_image_to_window(info->mlx, info->win, info->img.end,
		x * 50 + 10, y * 50 + 10);
}

void	draw_end2(t_info *info, int x, int y)
{
	draw_tile(info, x, y);
	mlx_put_image_to_window(info->mlx, info->win, info->img.end2,
		x * 50 + 10, y * 50 + 10);
}

void    draw_scoreboard(t_info *info, int x, int y)
{
    mlx_put_image_to_window(info->mlx, info->win, info->img.scoreboard,
        x, y);
	mlx_string_put(info->mlx, info->win, 60, 30, 0x99FFFFFF,
			"Movements : ");
	mlx_string_put(info->mlx, info->win, 150, 30, 0x99FFFFFF,
			ft_itoa(info->movement));
}

void    draw_ennemi(t_info *info, int x, int y)
{
    draw_tile(info, x, y);
    mlx_put_image_to_window(info->mlx, info->win, info->img.ennemi_1,
        x * 50 + 10, y * 50 + 10);
}

void    draw_ennemi2(t_info *info, int x, int y)
{
	draw_tile(info, x, y);
    mlx_put_image_to_window(info->mlx, info->win, info->img.ennemi_2,
        x * 50 + 10, y * 50 + 10);
}

void	draw_img(t_info *info, int i, int j)
{
	if (info->map[i][j] == '1')
		draw_wall(info, j, i);
	else if (info->start == 0 && info->map[i][j] == '0')
		draw_tile(info, j, i);
	else if (info->start == 0 && info->map[i][j] == 'P')
	{
		draw_tile(info, j, i);
		info->player.x = j;
		info->player.y = i;
	}
	else if (info->start == 0 && info->map[i][j] == 'C')
	{
		draw_coin(info, j, i);
		(info->coins)++;
	}
	else if (info->map[i][j] == 'E')
	{
		draw_end(info, j, i);
		info->exit_x = j; 
		info->exit_y = i; 
	}
	else if (info->map[i][j] == 'M')
	{
		draw_ennemi(info, j, i);
		info->ennemi.x = j;
		info->ennemi.x_restart = j;
		info->ennemi.y = i;
		info->ennemi.y_restart = i;
	}
	draw_scoreboard(info, 10, 10);
}
