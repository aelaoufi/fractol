/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:33:06 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/02/19 16:42:55 by aelaoufi         ###   ########.fr       */
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

void	error_msg(void)
{
	ft_printf("Parameter is invalid, please enter a valid set.");
	ft_printf("\n -mandelbrot\n -julia\n -julia 2\n -julia 3\n -julia 4\n \
-burningship\n");
	exit(0);
}
