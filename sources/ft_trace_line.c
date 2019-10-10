/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer_segment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:25:52 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/16 16:57:51 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_fill_pix(char *my_img, int x, int y, int color)
{
	int		i;
	int		k;
	int		h;
	int		w;

	h = HEIGHT - (HEIGHT / 9);
	w = WIDTH - ((WIDTH / 10) * 2);
	i = (((h - (h - y)) * w) - (w - x)) * 4;
	if (x < w && x > 0 && y < h && y > 0)
	{
		my_img[i + 0] = (color & 0xFF000000) >> 24;
		my_img[i + 1] = (color & 0x00FF0000) >> 16;
		my_img[i + 2] = (color & 0x0000FF00) >> 8;
		my_img[i + 3] = (color & 0x000000FF) >> 0;
	}
}

void	ft_case_two(t_struct *t, char *my_img, int col, int i)
{
	int		cumul;
	int		x;
	int		y;
	int		dx;
	int		dy;

	dx = t->bx - t->ax;
	dy = t->by - t->ay;
	x = (dx > 0 ? 1 : -1);
	y = (dy > 0 ? 1 : -1);
	dx = (dx < 0 ? -dx : dx);
	dy = (dy < 0 ? -dy : dy);
	cumul = dy / 2;
	while (i <= dy)
	{
		t->ay += y;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			t->ax += x;
		}
		ft_fill_pix(my_img, t->ax, t->ay, col);
		i++;
	}
}

void	ft_case_one(t_struct *t, char *my_img, int col, int i)
{
	int		cumul;
	int		x;
	int		y;
	int		dx;
	int		dy;

	dx = t->bx - t->ax;
	dy = t->by - t->ay;
	x = (dx > 0 ? 1 : -1);
	y = (dy > 0 ? 1 : -1);
	dx = (dx < 0 ? -dx : dx);
	dy = (dy < 0 ? -dy : dy);
	cumul = dx / 2;
	while (i <= dx)
	{
		t->ax += x;
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			t->ay += y;
		}
		ft_fill_pix(my_img, t->ax, t->ay, col);
		i++;
	}
}

void	ft_trace_line(t_struct *t, char *my_img, int col)
{
	int		i;
	int		dx;
	int		dy;

	dx = t->bx - t->ax;
	dy = t->by - t->ay;
	dx = (dx < 0 ? -dx : dx);
	dy = (dy < 0 ? -dy : dy);
	ft_fill_pix(my_img, t->ax, t->ay, col);
	i = 1;
	if (dx > dy)
		ft_case_one(t, my_img, col, i);
	else
		ft_case_two(t, my_img, col, i);
}
