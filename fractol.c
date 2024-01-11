/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaber <ysaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:46:15 by ysaber            #+#    #+#             */
/*   Updated: 2024/01/11 14:35:41 by ysaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	img;

	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		ft_mandelbrot(&img);
	if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		if (check_arg(av[2]) == 0 || check_arg(av[3]) == 0)
		{
			ft_putstr("ERROR : \nUsage: ./fractol julia [real] [imaginary]\n");
			return (0);
		}
		else
			ft_julia(&img, av);
	}
	if (ac == 2 && ft_strcmp(av[1], "burning_ship") == 0)
		ft_burning_ship(&img);
	else
	{
		ft_putstr("ERROR :");
		ft_putstr("Usage: ./fractol julia [real] [imaginary]\n or \n");
		ft_putstr("Usage: ./fractol mandelbrot\n or \n");
		ft_putstr("Usage: ./fractol burning_ship\n");
	}
	return (0);
}
