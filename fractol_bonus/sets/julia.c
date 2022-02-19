/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:31:41 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/02/19 13:38:15 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	draw_jul(t_px *p)
{
	if (p->iter <= MAX_ITER)
		p->buffer[(p->row * p->line_bytes) + p->col] \
			= p->color * p->iter;
}

void	calculs_julia(t_px *p)
{
	while (p->row < p->height)
	{
		p->col = 0;
		while (p->col < p->width)
		{
			p->real = p->col / (p->width / (p->re_max - p->re_min)) \
				+ p->re_min + p->movex;
			p->imgn = p->row / (p->height / (p->im_max - p->im_min)) \
				+ p->im_min + p->movey;
			p->x = p->real;
			p->y = p->imgn;
			p->iter = 0;
			while (p->iter < MAX_ITER && (p->x * p->x) + (p->y * p->y) <= 4)
			{
				p->xx = p->x;
				p->x = p->x * p->x - p->y * p->y + p->jul;
				p->y = 2 * p->y * p->xx + p->jul2;
				p->iter++;
			}
			draw_jul(p);
			p->col++;
		}
		p->row++;
	}
}

int	julia(t_px *p)
{
	p->buffer = (int *)mlx_get_data_addr(p->img, &(p->pixel_bits), \
		&(p->line_bytes), &(p->endian));
	p->line_bytes /= 4;
	p->col = 0;
	p->row = 0;
	p->width = 1000;
	p->height = 1000;
	calculs_julia(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img, 0, 0);
	return (0);
}
