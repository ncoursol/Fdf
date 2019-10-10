/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:54:53 by dberger           #+#    #+#             */
/*   Updated: 2019/07/16 17:00:56 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_place_pix(t_struct *t, int z, int i)
{
	int d;

	d = t->deep;
	if (z != 0)
		z = (z > 200) ? (z * d) / 5 : z * d;
	t->ax = t->ax * cos((t->anglz) * (M_PI / 180)) - t->ay
		* sin(((t->anglz) * (M_PI / 180)));
	t->ay = t->ax * sin((t->anglz) * (M_PI / 180)) + t->ay
		* cos(((t->anglz) * (M_PI / 180)));
	t->ay = (z >= 0) ? t->ay * cos((t->anglx) * (M_PI / 180))
		- z * sin(t->anglx * (M_PI / 180))
		: t->ay * cos((t->anglx) * (M_PI / 180))
		+ (-z) * sin((t->anglx) * (M_PI / 180));
	t->ax = (z >= 0) ? t->ax * cos((t->angly) * (M_PI / 180))
		- z * sin((t->angly) * (M_PI / 180))
		: t->ax * cos((t->angly * (M_PI / 180)))
		+ (-z) * sin((t->angly) * (M_PI / 180));
	return (z);
}

void	ft_trace_right(t_struct *t, char *my_img, char **tab, int i)
{
	int		z;
	int		p;
	char	*color;
	int		colr;

	i++;
	t->ax = (((i - (t->col * (i / t->col))) + 1) * t->sp) + t->startx;
	t->ay = (((i / t->col) + 1) * t->sp) + t->starty;
	z = ft_atoi(tab[i]);
	z = ft_place_pix(t, z, i);
	t->savey = t->ay;
	t->savex = t->ax;
	if (z > 0)
		colr = (z / t->deep) > CC ? BROWN : GREEN;
	if (z < 0)
		colr = (z / t->deep) > CC ? PURPLE : RED;
	else if (z == 0)
		colr = BLUE;
	if (z != t->deep && (z / t->deep) > CCUP)
		colr = WHITE;
	ft_trace_line(t, my_img, colr);
}

void	ft_trace_down(t_struct *t, char *my_img, char **tab, int i)
{
	int		z;
	int		save;
	int		color;

	i = ((i - 1) + t->col);
	t->ax = (((i - (t->col * (i / t->col))) + 1) * t->sp) + t->startx;
	t->ay = (((i / t->col) + 1) * t->sp) + t->starty;
	z = ft_atoi(tab[i]);
	z = ft_place_pix(t, z, i);
	if (i % t->col == 0)
	{
		t->savecol = t->ax;
		t->saveline = t->ay;
	}
	if (z > 0)
		color = (z / t->deep) > CC ? BROWN : GREEN;
	if (z < 0)
		color = (z / t->deep) > CC ? PURPLE : RED;
	else if (z == 0)
		color = BLUE;
	if (z != t->deep && (z / t->deep) > CCUP)
		color = WHITE;
	ft_trace_line(t, my_img, color);
}

void	ft_bxby(t_struct *t, char **tab, int i, int mode)
{
	int	z;

	z = ft_atoi(tab[i]);
	z = (z != 0) ? (z * t->deep) - (t->deep + z) : z;
	if (mode == 1)
	{
		t->by = (z && (i % t->col) != 0) ? t->savey
			: t->by * cos((t->anglx) * (M_PI / 180));
		t->bx = (z && (i % t->col) != 0) ? t->savex
			: t->bx * cos(t->angly * (M_PI / 180));
		t->bx = (z && (i % t->col) == 0) ? t->savecol : t->bx;
		t->by = (z && (i % t->col) == 0) ? t->saveline : t->by;
	}
	if (mode == 0)
	{
		t->by = (z >= 0) ? t->by * cos((t->anglx) * (M_PI / 180))
			- z * sin(t->anglx * (M_PI / 180))
			: t->by * cos((t->anglx) * (M_PI / 180))
			+ (-z) * sin((t->anglx) * (M_PI / 180));
		t->bx = (z >= 0) ? t->bx * cos((t->angly) * (M_PI / 180))
			- z * sin((t->angly) * (M_PI / 180))
			: t->bx * cos((t->angly * (M_PI / 180)))
			+ (-z) * sin((t->angly) * (M_PI / 180));
	}
}

void	ft_print_map(t_struct *t, char *my_img, char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		t->bx = (((i - (t->col * (i / t->col))) + 1) * t->sp) + t->startx;
		t->by = (((i / t->col) + 1) * t->sp) + t->starty;
		t->bx = t->bx * cos((t->anglz) * (M_PI / 180)) - t->by
			* sin(t->anglz * (M_PI / 180));
		t->by = t->bx * sin((t->anglz) * (M_PI / 180)) + t->by
			* cos((t->anglz) * (M_PI / 180));
		if (i == 0)
			ft_bxby(t, tab, i, 0);
		if (i > 0)
			ft_bxby(t, tab, i, 1);
		if ((i + 1) % (t->col) != 0 && tab[i + 1])
			ft_trace_right(t, my_img, tab, i);
		if ((i + t->col) <= (t->col * t->line) - 1)
			ft_trace_down(t, my_img, tab, i + 1);
		i++;
	}
}
