/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaber <ysaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:46:28 by ysaber            #+#    #+#             */
/*   Updated: 2024/01/04 21:04:06 by ysaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	close_program(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	exit(0);
	return (0);
}

static double	help_atod(char *str, double res, int *dec, double *fr)
{
	if (*str >= '0' && *str <= '9')
	{
		if (!(*dec))
		{
			res = res * 10.0 + (*str - '0');
		}
		else
		{
			res = res + (*str - '0') * (*fr);
			(*fr) /= 10.0;
		}
	}
	else if (*str == '.')
		(*dec) = 1;
	return (res);
}

double	ft_atod(char *str)
{
	double	result;
	double	fr;
	int		sign;
	int		dec;

	result = 0.0;
	fr = 0.1;
	sign = 1;
	dec = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str != '\0')
	{
		result = help_atod(str, result, &dec, &fr);
		str++;
	}
	return (sign * result);
}
