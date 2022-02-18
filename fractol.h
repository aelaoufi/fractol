/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:36:56 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/02/18 18:00:14 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_ITER 100

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_px
{
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	double	zoom;
	double	width;
	double	height;
	double	x;
	double	y;
	double	re_max;
	double	re_min;
	double	im_max;
	double	im_min;
	double	mousere;
	double	mouseim;
	int		col;
	int		row;
	double	real;
	double	imgn;
	double	xx;
	double	jul;
	double	jul2;
	int		*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		color;
	int		type;
	double	movex;
	double	movey;
	int		iter;
	int		ctype;
}				t_px;

int		close(t_px *p);
void	initialize(t_px *p);
int		mousepos(int x, int y, t_px *p);
void	applyzoom(t_px *e);
double	interpolate(double start, double end, double interpolation);
int		zoom(int key, int x, int y, t_px *p);
int		mandelbrot(t_px *p);
int		julia(t_px *p);
int		ft_strcmp(char	*set, char	*av);
size_t	ft_strlen(char *str);
void	setto_draw(t_px *px, int ac, char **av);
void	error_msg(void);
char	*ft_strdup(char *src);
int		movement(int key, t_px *p);
void	type(t_px *p);
int		sterling(t_px *p);
int		pars(t_px *p, int ac, char **av);
void	init_julia(t_px *p);
int		movey(int key, t_px *p);
int		sterling(t_px *p);
void	coloring(t_px *p);

#endif
