/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaber <ysaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:46:25 by ysaber            #+#    #+#             */
/*   Updated: 2024/01/07 13:10:31 by ysaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0'))
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	free_all(t_data *img)
{
	free(img->mlx);
	exit(0);
}

int	check_arg(const char *str)
{
	int	i;
	int	dot_c;
	int	digit_c;

	i = 0;
	dot_c = 0;
	digit_c = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit_c++;
		else if (str[i] == '.')
			dot_c++;
		else
			return (0);
		i++;
	}
	return (digit_c > 0 && dot_c <= 1);
}
