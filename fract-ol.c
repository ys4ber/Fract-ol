/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaber <ysaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:46:15 by ysaber            #+#    #+#             */
/*   Updated: 2024/01/04 21:23:24 by ysaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	img;

	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		ft_mandelbrot(&img);
	if (ac == 4 && ft_strcmp(av[1], "julia") == 0 && ft_atod(av[2]) != 0
		&& ft_atod(av[3]) != 0)
		ft_julia(&img, av);
	if (ac == 2 && ft_strcmp(av[1], "burning_ship") == 0)
		ft_burning_ship(&img);
	else
	{
		ft_putstr("ERROR :");
		ft_putstr("Usage: ./fractol julia [real] [imaginary]\n or \n");
		ft_putstr("Usage: ./fractol mandelbrot\n o \n");
		ft_putstr("Usage: ./fractol burning_ship\n");
	}
	return (0);
}
