/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:31:28 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/12 11:31:31 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	num_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	num_length(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*out;
	int			len;

	len = num_length(n);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (0);
	out[len--] = '\0';
	if (n < 0)
	{
		out[0] = '-';
		n *= -1;
	}
	if (n == 0)
		out[len] = '0';
	while (n != 0)
	{
		out[len] = '0' + num_abs(n % 10);
		n /= 10;
		len--;
	}
	return (out);
}
