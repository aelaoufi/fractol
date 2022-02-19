/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:31:12 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/02/19 14:05:09 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int	destroy(int key, t_px *p)
{
	if (key == 53)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit (0);
	}
	return (0);
}

int	movex(int key, t_px *p)
{
	if (key == 123)
	{
		p->movex -= 0.04;
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		type(p);
	}
	if (key == 124)
	{
		p->movex += 0.04;
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		type(p);
	}
	return (0);
}

int	movey(int key, t_px *p)
{
	destroy(key, p);
	movex(key, p);
	if (key == 126)
	{
		p->movey -= 0.04;
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		type(p);
	}
	if (key == 125)
	{
		p->movey += 0.04;
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		type(p);
	}
	return (0);
}