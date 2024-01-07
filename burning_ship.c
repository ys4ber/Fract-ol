/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaber <ysaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:46:03 by ysaber            #+#    #+#             */
/*   Updated: 2024/01/05 14:05:27 by ysaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(t_data *img, int x, int y)
{
	t_complexe	c;
	t_complexe	z;
	t_complexe	tmp;
	int			i;
	int			color;

	i = 0;
	c.re = (x - WIDTH / 2.0) * 4.0 / WIDTH * img->zoom + img->offset_x;
	c.im = (y - HEIGHT / 2.0) * 4.0 / WIDTH * img->zoom + img->offset_y;
	z.re = 0;
	z.im = 0;
	while (z.re * z.re + z.im * z.im < 4 && i < MAX_ITER)
	{
		tmp.re = ft_abs(z.re * z.re - z.im * z.im + c.re);
		tmp.im = ft_abs(2 * z.re * z.im + c.im);
		z.re = tmp.re;
		z.im = tmp.im;
		i++;
	}
	if (i < MAX_ITER)
		color = create_trgb(32, 255 * i / MAX_ITER, 25, 2);
	else
		color = create_trgb(0, 0, 0, 0);
	my_mlx_pixel_put(img, x, y, color * i);
}

void	draw_burning_ship(t_data *img)
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
			burning_ship(img, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

int	mouse_hook_b(int button, int x, int y, t_data *img)
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
	draw_burning_ship(img);
	return (0);
}

int	deal_key_b(int key, t_data *img)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		img->offset_x -= 0.1 * img->zoom;
	if (key == 124)
		img->offset_x += 0.1 * img->zoom;
	if (key == 125)
		img->offset_y += 0.1 * img->zoom;
	if (key == 126)
		img->offset_y -= 0.1 * img->zoom;
	mlx_clear_window(img->mlx, img->win);
	draw_burning_ship(img);
	return (0);
}

void	ft_burning_ship(t_data *img)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		free_all(img);
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "burning ship");
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
	img->zoom = 1;
	img->offset_x = 0;
	img->offset_y = 0;
	draw_burning_ship(img);
	mlx_hook(img->win, 2, 0, deal_key_b, img);
	mlx_hook(img->win, 4, 0, mouse_hook_b, img);
	mlx_hook(img->win, 17, 0, close_program, img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_loop(img->mlx);
}
