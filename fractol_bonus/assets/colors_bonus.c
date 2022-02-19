/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:32:59 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/02/19 13:37:31 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	coloring(t_px *p)
{
	if (p->ctype == 1)
		p->color = 0XFFFFFF;
	if (p->ctype == 2)
		p->color = 0Xff00f0;
	if (p->ctype == 3)
		p->color = 0XFFFF00;
	if (p->ctype == 4)
		p->color = 0XFFF000;
	if (p->ctype == 5)
		p->color = 0Xff0ff0;
	if (p->ctype == 6)
		p->color = 0Xf00fff;
	if (p->ctype == 7)
		p->color = 0Xf00ff0;
	if (p->ctype == 8)
		p->color = 0X0f00f0;
}
