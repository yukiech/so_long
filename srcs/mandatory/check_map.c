/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:12:31 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/11 14:30:22 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char(t_info *info, int i, int j)
{
	if (!is_valid_char(info->map[i][j]))
		print_end(
			"La map ne doit contenir que des 0, 1, C, E, P, M.\n", 50);
	if (i == 0 || i == info->map_height - 1
		|| j == 0 || j == info->map_width - 1)
	{
		if (info->map[i][j] != '1')
			print_end("Ta map a un trou\n", 17);
	}
}

void	init_ready(t_ready *ready)
{
	ready->player = 0;
	ready->coin = 0;
	ready->end = 0;
}

void	check_equipped(t_info *info, int i, int j, t_ready *ready)
{
	if (info->map[i][j] == 'P')
		ready->player++;
	else if (info->map[i][j] == 'C')
		ready->coin++;
	else if (info->map[i][j] == 'E')
		ready->end++;
	else if (info->map[i][j] == 'M')
		info->ennemi.exist = 1;
}

void	check_ready(t_ready ready)
{
	if (ready.player != 1)
		print_end("Pas de P ? Pas facile de jouer sans !\n", 38);
	if (ready.coin == 0)
		print_end("Pas de C ? Il lui faut des pieces !\n", 36);
	if (ready.end == 0)
		print_end("Pas de E ? Comment tu vas sortir ?\n", 35);
}

void	check_map(t_info *info)
{
	t_ready	ready;
	int		i;
	int		j;

	i = 0;
	init_ready(&ready);
	while (i < info->map_height)
	{
		j = 0;
		if (ft_strlen(info->map[i]) != info->map_width)
			print_end("Ta map est pas rectangle !\n", 27);
		while (j < info->map_width)
		{
			check_char(info, i, j);
			check_equipped(info, i, j, &ready);
			j++;
		}
		i++;
	}
	check_ready(ready);
}
