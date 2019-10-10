/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:12:51 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/14 19:50:31 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_effect(int key, t_struct *t)
{
	ft_erase(t);
	if (key == 125)
		t->anglx -= 5;
	else if (key == 126)
		t->anglx += 5;
	else if (key == 124)
		t->angly -= 5;
	else if (key == 123)
		t->angly += 5;
	else if (key == 83)
		t->anglz += 5;
	else if (key == 84)
		t->anglz -= 5;
	else if (key == 78)
		t->sp -= 1;
	else if (key == 69)
		t->sp += 1;
	else if (key == 75)
		t->deep += 1;
	else if (key == 67)
		t->deep -= 1;
	ft_img(t, t->tab, t->pt, t->my);
}

void		ft_print_press(int x, int y, t_struct *t, char *b)
{
	int		i;
	int		j;

	i = x;
	while (i++ != x + 39)
	{
		j = y;
		while (j++ != y + 39)
			mlx_pixel_put(t->mlx, t->win, j, i, 0xFFF700);
	}
	mlx_string_put(t->mlx, t->win, y + 15, x + 8, 0x999999, b);
}

void		ft_print_release(int x, int y, t_struct *t, char *b)
{
	int		i;
	int		j;

	i = x;
	while (i++ != x + 39)
	{
		j = y;
		while (j++ != y + 39)
			mlx_pixel_put(t->mlx, t->win, j, i, 0x232323);
	}
	mlx_string_put(t->mlx, t->win, y + 15, x + 8, 0xBDBDBD, b);
}

void		ft_key_print(int key, t_struct *t, int size)
{
	if (key == 125)
		ft_print_press((HEIGHT / 6), size, t, "v");
	else if (key == 126)
		ft_print_press((HEIGHT / 6), size + 60, t, "^");
	else if (key == 124)
		ft_print_press((HEIGHT / 6) * 2, size + 60, t, ">");
	else if (key == 123)
		ft_print_press((HEIGHT / 6) * 2, size, t, "<");
	else if (key == 83)
		ft_print_press((HEIGHT / 6) * 3, size, t, "1");
	else if (key == 84)
		ft_print_press((HEIGHT / 6) * 3, size + 60, t, "2");
	else if (key == 78)
		ft_print_press((HEIGHT / 6) * 5, size + 60, t, "-");
	else if (key == 69)
		ft_print_press((HEIGHT / 6) * 5, size, t, "+");
	else if (key == 75)
		ft_print_press((HEIGHT / 6) * 4, size, t, "/");
	else if (key == 67)
		ft_print_press((HEIGHT / 6) * 4, size + 60, t, "*");
	ft_effect(key, t);
}

void		ft_key_press(int key, t_struct *t, int size, int mode)
{
	if (mode == 1)
		ft_key_print(key, t, size);
	else
	{
		if (key == 125)
			ft_print_release((HEIGHT / 6), size, t, "v");
		else if (key == 126)
			ft_print_release((HEIGHT / 6), size + 60, t, "^");
		else if (key == 124)
			ft_print_release((HEIGHT / 6) * 2, size + 60, t, ">");
		else if (key == 123)
			ft_print_release((HEIGHT / 6) * 2, size, t, "<");
		else if (key == 75)
			ft_print_release((HEIGHT / 6) * 4, size, t, "/");
		else if (key == 67)
			ft_print_release((HEIGHT / 6) * 4, size + 60, t, "*");
		else if (key == 83)
			ft_print_release((HEIGHT / 6) * 3, size, t, "1");
		else if (key == 84)
			ft_print_release((HEIGHT / 6) * 3, size + 60, t, "2");
		else if (key == 78)
			ft_print_release((HEIGHT / 6) * 5, size + 60, t, "-");
		else if (key == 69)
			ft_print_release((HEIGHT / 6) * 5, size, t, "+");
	}

