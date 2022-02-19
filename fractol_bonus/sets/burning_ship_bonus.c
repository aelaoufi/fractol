/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:46:30 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/02/19 13:55:03 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	draw_ster(t_px *p)
{
	if (p->iter <= MAX_ITER)
		p->buffer[(p->row * p->line_bytes) + p->col] \
			= p->color * p->iter;
}

void	calculs_sterling(t_px *p)
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
			p->x = 0;
			p->y = 0;
			p->iter = 0;
			while (p->iter < MAX_ITER && (p->x * p->x) + (p->y * p->y) <= 4)
			{
				p->xx = fabs(p->x * p->x - p->y * p->y + p->real);
				p->y = fabs(2 * p->y * p->x + p->imgn);
				p->x = p->xx;
				p->iter++;
			}
			draw_ster(p);
			p->col++;
		}
		p->row++;
	}
}

int	sterling(t_px *p)
{
	p->buffer = (int *)mlx_get_data_addr(p->img, &(p->pixel_bits), \
		&(p->line_bytes), &(p->endian));
	p->line_bytes /= 4;
	p->col = 0;
	p->row = 0;
	p->width = 1000;
	p->height = 1000;
	calculs_sterling(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img, 0, 0);
	return (0);
}
