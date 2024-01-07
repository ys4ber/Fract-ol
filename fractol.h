/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaber <ysaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:46:20 by ysaber            #+#    #+#             */
/*   Updated: 2024/01/07 11:42:54 by ysaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define WIDTH 1000
# define HEIGHT 900
# define MAX_ITER 100

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	**av;
	int		bpp;
	int		len;
	int		end;
	double	zoom;
	double	offset_x;
	double	offset_y;
}			t_data;

typedef struct s_complexe
{
	double	re;
	double	im;
}			t_complexe;

// mandelbrot :

void		ft_mandelbrot(t_data *img);
int			deal_key_m(int key, t_data *img);
int			mouse_hook_m(int button, int x, int y, t_data *img);
void		draw_mandelbrot(t_data *img);
void		mandelbrot(t_data *img, int x, int y);

// julia :

void		ft_julia(t_data *img, char **av);
int			deal_key(int key, t_data *img);
int			mouse_hook(int button, int x, int y, t_data *img);
void		draw_julia(t_data *img, char **av);
void		julia(t_data *img, int x, int y, char **av);

// burning ship :

void		ft_burning_ship(t_data *img);
int			deal_key_b(int key, t_data *img);
int			mouse_hook_b(int button, int x, int y, t_data *img);
void		draw_burning_ship(t_data *img);
void		burning_ship(t_data *img, int x, int y);

// general :

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
int			close_program(t_data *img);
double		ft_atod(char *str);

// utils :
void		ft_putstr(char *str);
double		ft_abs(double x);
int			ft_strcmp(const char *s1, const char *s2);
void 		free_all(t_data *img);
int 		check_arg(const char *str);

#endif