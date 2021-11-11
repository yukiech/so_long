/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:13:21 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/11 19:36:11 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			draw_img(info, i, j);
			j++;
		}
		i++;
	}
	if (info->start == 0)
	{
		draw_player(info, KEY_S);
		info->start = 1;
	}
}

void	init(t_info *info, char *file)
{
	load_map(info, file);
	check_map(info);
	info->mlx = mlx_init();
	info->movement = 0;
	info->win = mlx_new_window(info->mlx, 50 * info->map_width,
			(50 * info->map_height), "The Binding of Pas Isaac");
	if (info->mlx == NULL || info->win == NULL)
		print_end("Soucis de creation de fenetre\n", 30);
	info->start = 0;
	info->coins = 0;
	info->ended = 0;
	info->ennemi.move = 0;
	load_images(info, 0, 0);
	check_images(info);
	sound_music();
	draw_map(info);
}

void	game(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		print_end("Seulement une map en argument svp.", 34);
	init(&info, argv[1]);
	info.argc = argc;
	info.argv = argv;
	mlx_hook(info.win, KEY_PRESS, 0, &deal_key, &info);
	mlx_hook(info.win, KEY_EXIT, 0, &ft_close, &info);
	mlx_loop(info.mlx);
}

int	main(int argc, char **argv)
{
	game(argc, argv);
	return (0);
}
