/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:31:17 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/02/17 14:47:23 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	type(t_px *p)
{
	if (p->type == 1)
		mandelbrot(p);
	else if (p->type == 6)
		sterling(p);
	else if (p->type == 2 || p->type == 3 || p->type == 4 || p->type == 5)
		julia(p);
}

int	zoom(int key, int x, int y, t_px *p)
{
	(void)x;
	(void)y;
	if (key == 1)
	{
		initialize(p);
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		type(p);
	}
	if (key == 4)
	{
		p->zoom = 1;
		p->zoom *= 1.12;
		applyzoom(p);
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		type(p);
	}
	if (key == 5)
	{
		p->zoom = 1;
		p->zoom /= 1.12;
		applyzoom(p);
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		type(p);
	}
	return (0);
}

int	mousepos(int x, int y, t_px *p)
{
	p->mousere = (double)x / (p->width / (p->re_max - p->re_min)) + p->re_min;
	p->mouseim = (double)y / (p->height / (p->im_max - p->im_min)) + p->im_min;
	return (0);
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	applyzoom(t_px *e)
{
	e->re_min = interpolate(e->mousere, e->re_min, e->zoom);
	e->im_min = interpolate(e->mouseim, e->im_min, e->zoom);
	e->re_max = interpolate(e->mousere, e->re_max, e->zoom);
	e->im_max = interpolate(e->mouseim, e->im_max, e->zoom);
}
