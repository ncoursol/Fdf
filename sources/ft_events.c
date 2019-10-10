/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:46:12 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/16 19:27:02 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move(int key, t_struct *t)
{
	if (key == 0)
		t->startx -= 20;
	if (key == 1)
		t->starty += 20;
	if (key == 2)
		t->startx += 20;
	if (key == 13)
		t->starty -= 20;
	ft_img(t, t->tab, t->pt, t->my);
}

int		key_release(int key, t_struct *t)
{
	int		size;

	size = (WIDTH - ((WIDTH / 10) * 2) + 30);
	if (key == 53)
	{
		mlx_destroy_image(t->mlx, t->my);
		mlx_destroy_window(t->mlx, t->win);
		exit(0);
	}
	else
		ft_key_press(key, t, size, 0);
	return (0);
}

int		key_press(int key, t_struct *t)
{
	int		size;

	size = (WIDTH - ((WIDTH / 10) * 2) + 30);
	if (key == 53)
	{
		mlx_destroy_image(t->mlx, t->my);
		mlx_destroy_window(t->mlx, t->win);
		exit(0);
	}
	else if (key == 13 || key == 0 || key == 1 || key == 2)
		ft_move(key, t);
	else
		ft_key_press(key, t, size, 1);
	return (0);
}
