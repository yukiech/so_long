/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:14:36 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/12 13:42:48 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_info *info, int img_width, int img_height)
{
	info->img.tile = mlx_xpm_file_to_image(info->mlx,
			"./img/map/grass.xpm", &img_width, &img_height);
	info->img.wall = mlx_xpm_file_to_image(info->mlx,
			"./img/map/rock.xpm", &img_width, &img_height);
	info->img.player_w1 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/isaac_up.xpm", &img_width, &img_height);
	info->img.player_w2 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/isaac_up2.xpm", &img_width, &img_height);
	info->img.player_a1 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/isaac_left.xpm", &img_width, &img_height);
	info->img.player_a2 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/isaac_left2.xpm", &img_width, &img_height);
	info->img.player_s1 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/isaac_down.xpm", &img_width, &img_height);
	info->img.player_s2 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/isaac_down2.xpm", &img_width, &img_height);
	info->img.player_d1 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/isaac_right.xpm", &img_width, &img_height);
	info->img.player_d2 = mlx_xpm_file_to_image(info->mlx,
			"./img/char/isaac_right2.xpm", &img_width, &img_height);
	load_images2(info, img_width, img_height);
}

void	load_images2(t_info *info, int img_width, int img_height)
{
	info->img.coin1 = mlx_xpm_file_to_image(info->mlx,
			"./img/coin/coin.xpm", &img_width, &img_height);
	info->img.end = mlx_xpm_file_to_image(info->mlx,
			"./img/map/exit.xpm", &img_width, &img_height);
	info->img.end2 = mlx_xpm_file_to_image(info->mlx,
			"./img/map/exit2.xpm", &img_width, &img_height);
	info->img.ennemi_1 = mlx_xpm_file_to_image(info->mlx,
			"./img/enemy/ennemi1.xpm", &img_width, &img_height);
	info->img.ennemi_2 = mlx_xpm_file_to_image(info->mlx,
			"./img/enemy/ennemi2.xpm", &img_width, &img_height);
	info->img.scoreboard = mlx_xpm_file_to_image(info->mlx,
			"./img/map/scoreboard.xpm", &img_width, &img_height);
	info->img.endscreen = mlx_xpm_file_to_image(info->mlx,
			"./img/map/endscreen.xpm", &img_width, &img_height);
	info->img.winscreen = mlx_xpm_file_to_image(info->mlx,
			"./img/map/winscreen.xpm", &img_width, &img_height);
}

void	check_images(t_info *info)
{
	if (info->img.tile == NULL)
		print_end("Image herbe invalide\n", 21);
	if (info->img.wall == NULL)
		print_end("Image mur invalide\n", 19);
	if (info->img.player_w1 == NULL)
		print_end("Image isaac up invalide\n", 24);
	if (info->img.player_w2 == NULL)
		print_end("Image isaac up2 invalide\n", 25);
	if (info->img.player_a1 == NULL)
		print_end("Image isaac left invalide\n", 26);
	if (info->img.player_a2 == NULL)
		print_end("Image isaac left2 invalide\n", 27);
	if (info->img.player_s1 == NULL)
		print_end("Image isaac down invalide\n", 26);
	if (info->img.player_s2 == NULL)
		print_end("Image isaac down2 invalide\n", 27);
	if (info->img.player_d1 == NULL)
		print_end("Image isaac right invalide\n", 27);
	if (info->img.player_d2 == NULL)
		print_end("Image isaac right2 invalide\n", 28);
	if (info->img.coin1 == NULL)
		print_end("Image coin invalide\n", 20);
	if (info->img.end == NULL)
		print_end("Image exit invalide\n", 20);
}
