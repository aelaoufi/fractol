/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:33:06 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/02/18 15:07:30 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	initialize(t_px *p)
{
	p->zoom = 1;
	p->movex = 0;
	p->movey = 0;
	p->re_max = 2.0;
	p->re_min = -2.0;
	p->im_max = 2.0;
	p->im_min = -2.0;
	p->line_bytes /= 4;
	p->col = 0;
	p->row = 0;
	p->width = 1000;
	p->height = 1000;
	p->ctype = 1;
}

void	setto_draw(t_px *px, int ac, char **av)
{
	if (ac == 1)
		error_msg();
	if (ft_strcmp("mandelbrot", av[1]) == 1 && ac == 2)
		mandelbrot(px);
	else if (ft_strcmp("burningship", av[1]) == 1 && ac == 2)
		sterling(px);
	else if (ft_strcmp("julia", av[1]) == 1 && ac == 2)
		julia(px);
	else if (ft_strcmp("julia", av[1]) == 1 && av[2][0] == '2' && ac == 3)
		julia(px);
	else if (ft_strcmp("julia", av[1]) == 1 && av[2][0] == '3')
		julia(px);
	else if (ft_strcmp("julia", av[1]) == 1 && av[2][0] == '4')
		julia(px);
	else
		error_msg();
}

int	close(t_px *p)
{
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	exit(0);
	return (0);
}
