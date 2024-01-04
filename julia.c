/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaber <ysaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:46:37 by ysaber            #+#    #+#             */
/*   Updated: 2024/01/04 21:05:07 by ysaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_data *img, int x, int y, char **av)
{
	t_complexe	c;
	t_complexe	z;
	t_complexe	tmp;
	int			i;
	int			color;

	i = 0;
	c.re = ft_atod(av[2]);
	c.im = ft_atod(av[3]);
	z.re = (x - WIDTH / 2.0) * 4.0 / WIDTH * img->zoom + img->offset_x;
	z.im = (y - HEIGHT / 2.0) * 4.0 / WIDTH * img->zoom + img->offset_y;
	while (z.re * z.re + z.im * z.im < 4 && i < MAX_ITER)
	{
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		tmp.im = 2 * z.re * z.im + c.im;
		z.re = tmp.re;
		z.im = tmp.im;
		i++;
	}
	color = create_trgb(0, 255 * i / MAX_ITER, i / MAX_ITER, i / MAX_ITER);
	my_mlx_pixel_put(img, x, y, color);
}

void	draw_julia(t_data *img, char **av)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			julia(img, x, y, av);
			y++;
		}
		x++;
	}
}

int	mouse_hook(int button, int x, int y, t_data *img)
{
	if (button == 4)
		img->zoom *= 1.1;
	if (button == 5)
		img->zoom /= 1.1;
	if (button == 1)
	{
		img->offset_x = (x - WIDTH / 2.0) * 4.0 / WIDTH * img->zoom
			+ img->offset_x;
		img->offset_y = (y - HEIGHT / 2.0) * 4.0 / WIDTH * img->zoom
			+ img->offset_y;
	}
	mlx_clear_window(img->mlx, img->win);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	draw_julia(img, img->av);
	return (0);
}

int	deal_key(int key, t_data *img)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		img->offset_x -= 0.1 / img->zoom;
	if (key == 124)
		img->offset_x += 0.1 / img->zoom;
	if (key == 125)
		img->offset_y += 0.1 / img->zoom;
	if (key == 126)
		img->offset_y -= 0.1 / img->zoom;
	draw_julia(img, img->av);
	mlx_clear_window(img->mlx, img->win);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

void	ft_julia(t_data *img, char **av)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Julia");
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
	img->zoom = 1;
	img->offset_x = 0;
	img->offset_y = 0;
	img->av = av;
	draw_julia(img, av);
	mlx_hook(img->win, 4, 1L << 0, mouse_hook, img);
	mlx_hook(img->win, 2, 0, deal_key, img);
	mlx_hook(img->win, 17, 0, close_program, img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_loop(img->mlx);
}
