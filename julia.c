/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaber <ysaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:46:37 by ysaber            #+#    #+#             */
/*   Updated: 2024/01/11 20:36:10 by ysaber           ###   ########.fr       */
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
	z.im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT * img->zoom + img->offset_y;
	while (z.re * z.re + z.im * z.im < 4 && i < MAX_ITER)
	{
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		tmp.im = 2 * z.re * z.im + c.im;
		z.re = tmp.re;
		z.im = tmp.im;
		i++;
	}
	if (i < MAX_ITER)
		color = img->color.r * i % 255 << 16 | img->color.g * i \
			% 255 << 8 | img->color.b * i % 255;
	else
		color = 0;
	my_mlx_pixel_put(img, x, y, color * i);
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
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

int	mouse_hook(int button, int x, int y, t_data *img)
{
	x = 0;
	y = 0;
	if (button == 4)
		img->zoom *= 1.1;
	if (button == 5)
		img->zoom /= 1.1;
	mlx_clear_window(img->mlx, img->win);
	draw_julia(img, img->av);
	return (0);
}

int	deal_key(int key, t_data *img)
{
	if (key == 53)
	{
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	if (key == 15)
		img->color.r += 1;
	if (key == 5)
		img->color.g += 1;
	if (key == 11)
		img->color.b += 1;
	if (key == 123)
		img->offset_x -= 0.1 * img->zoom;
	if (key == 124)
		img->offset_x += 0.1 * img->zoom;
	if (key == 125)
		img->offset_y += 0.1 * img->zoom;
	if (key == 126)
		img->offset_y -= 0.1 * img->zoom;
	draw_julia(img, img->av);
	mlx_clear_window(img->mlx, img->win);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

void	ft_julia(t_data *img, char **av)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		free_all(img);
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Julia");
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
	img->zoom = 1;
	img->offset_x = 0;
	img->offset_y = 0;
	img->av = av;
	img->color.r = 1;
	img->color.g = 9;
	img->color.b = 5;
	draw_julia(img, av);
	mlx_hook(img->win, 4, 0, mouse_hook, img);
	mlx_hook(img->win, 2, 0, deal_key, img);
	mlx_hook(img->win, 17, 0, close_program, img);
	mlx_loop(img->mlx);
}
