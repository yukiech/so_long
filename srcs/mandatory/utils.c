/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:14:46 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/08 13:05:27 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_info *info)
{
	(void)info;
	exit(0);
}

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

void	print_end(char *str, int len)
{
	write(1, str, len);
	exit(1);
}
