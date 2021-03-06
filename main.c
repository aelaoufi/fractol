/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:37:01 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/02/20 20:04:59 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setto_draw(t_px *px, int ac, char **av)
{
	if (ft_strcmp("mandelbrot", av[1]) == 1 && ac == 2)
		mandelbrot(px);
	else if (ft_strcmp("julia", av[1]) == 1 && ac == 2)
		julia(px);
	else if (ft_strcmp("julia", av[1]) == 1 && av[2][0] == '2' \
		&& av[2][1] == '\0')
		julia(px);
	else if (ft_strcmp("julia", av[1]) == 1 && av[2][0] == '3' \
		&& av[2][1] == '\0')
		julia(px);
	else if (ft_strcmp("julia", av[1]) == 1 && av[2][0] == '4' \
		&& av[2][1] == '\0')
		julia(px);
	else
		error_msg();
}

int	pars(t_px *p, int ac, char **av)
{
	if (ft_strcmp("mandelbrot", av[1]) == 1 && ac == 2)
		p->type = 1;
	else if (ft_strcmp("julia", av[1]) == 1 && ac == 2)
		p->type = 2;
	else if (ft_strcmp("julia", av[1]) == 1 && av[2][0] == '2')
		p->type = 3;
	else if (ft_strcmp("julia", av[1]) == 1 && av[2][0] == '3')
		p->type = 4;
	else if (ft_strcmp("julia", av[1]) == 1 && av[2][0] == '4')
		p->type = 5;
	return (0);
}

void	init_julia(t_px *p)
{
	if (p->type == 2)
	{
		p->jul = -0.038088;
		p->jul2 = 0.9754633;
	}
	if (p->type == 3)
	{
		p->jul = 0.285;
		p->jul2 = 0.013;
	}
	if (p->type == 4)
	{
		p->jul = -0.8;
		p->jul2 = 0.156;
	}
	if (p->type == 5)
	{
		p->jul = 0.3;
		p->jul2 = 0.5;
	}
}

int	main(int ac, char **argv)
{
	t_px	*px;

	if (ac == 1)
		error_msg();
	px = malloc(sizeof(t_px));
	px->mlx_ptr = mlx_init();
	px->win_ptr = mlx_new_window(px->mlx_ptr, 1000, 1000, "Fractol");
	px->img = mlx_new_image(px->mlx_ptr, 1000, 1000);
	pars(px, ac, argv);
	initialize(px);
	init_julia(px);
	applyzoom(px);
	setto_draw(px, ac, argv);
	mlx_hook(px->win_ptr, 4, 0, zoom, (void *)px);
	mlx_hook(px->win_ptr, 17, 0, destr, (void *)px);
	mlx_hook(px->win_ptr, 6, 0, mousepos, (void *)px);
	mlx_key_hook(px->win_ptr, esc, (void *)px);
	mlx_loop(px->mlx_ptr);
}
