/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:31:12 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/02/22 14:00:47 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	esc(int key, t_px *p)
{
	if (key == 53)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit (0);
	}
	return (0);
}

int	destr(t_px *p)
{
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	exit(0);
}
