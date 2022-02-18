/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:37:01 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/02/18 15:13:18 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*error_msg(void)
{
	printf("Parameter is invalid, please enter a valid set.");
	printf("\n -mandelbrot\n -julia\n -julia 2\n -julia 3\n -julia 4\n");
	exit(0);
}

int	color(int key, t_px *p)
{
	if (key == 12)
	{
		p->ctype += 1;
		coloring(p);
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		type(p);
	}
	if (p->ctype > 8)
	{
		p->ctype = 1;
		coloring(p);
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		type(p);
	}
	return (0);
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
	else if (ft_strcmp("burningship", av[1]) == 1 && ac == 2)
		p->type = 6;
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

	px = malloc(sizeof(t_px));
	px->mlx_ptr = mlx_init();
	px->win_ptr = mlx_new_window(px->mlx_ptr, 1000, 1000, "Fractol");
	px->img = mlx_new_image(px->mlx_ptr, 1000, 1000);
	pars(px, ac, argv);
	initialize(px);
	coloring(px);
	init_julia(px);
	applyzoom(px);
	setto_draw(px, ac, argv);
	mlx_hook(px->win_ptr, 2, 0, color, (void *)px);
	mlx_hook(px->win_ptr, 4, 0, zoom, (void *)px);
	mlx_hook(px->win_ptr, 17, 0, close, (void *)px);
	mlx_hook(px->win_ptr, 6, 0, mousepos, (void *)px);
	mlx_key_hook(px->win_ptr, movey, (void *)px);
	mlx_loop(px->mlx_ptr);
}
