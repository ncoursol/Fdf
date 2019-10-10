/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:47:18 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/16 19:59:05 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_erase(t_struct *t)
{
	int		i;
	int		j;

	j = HEIGHT / 6;
	i = (WIDTH - ((WIDTH / 10) * 2) + 30) + 50;
	mlx_string_put(t->mlx, t->win, i, j + 60, 0x232323, "0000");
	mlx_string_put(t->mlx, t->win, i, j * 2 + 60, 0x232323, "0000");
	mlx_string_put(t->mlx, t->win, i, j * 3 + 60, 0x232323, "0000");
	mlx_string_put(t->mlx, t->win, i, j * 4 + 60, 0x232323, "0000");
	mlx_string_put(t->mlx, t->win, i, j * 5 + 60, 0x232323, "0000");
	i = (WIDTH - ((WIDTH / 10) * 2) + 30) + 49;
	mlx_string_put(t->mlx, t->win, i, j + 60, 0x232323, "0000");
	mlx_string_put(t->mlx, t->win, i, j * 2 + 60, 0x232323, "0000");
	mlx_string_put(t->mlx, t->win, i, j * 3 + 60, 0x232323, "0000");
	mlx_string_put(t->mlx, t->win, i, j * 4 + 60, 0x232323, "0000");
	mlx_string_put(t->mlx, t->win, i, j * 5 + 60, 0x232323, "0000");
	i = (WIDTH - ((WIDTH / 10) * 2) + 30) + 51;
	mlx_string_put(t->mlx, t->win, i, j + 60, 0x232323, "0000");
	mlx_string_put(t->mlx, t->win, i, j * 2 + 60, 0x232323, "0000");
	mlx_string_put(t->mlx, t->win, i, j * 3 + 60, 0x232323, "0000");
	mlx_string_put(t->mlx, t->win, i, j * 4 + 60, 0x232323, "0000");
	mlx_string_put(t->mlx, t->win, i, j * 5 + 60, 0x232323, "0000");
}

void	ft_macros(t_struct *t, char **tab)
{
	int		w;
	int		h;

	h = HEIGHT - (HEIGHT / 9);
	w = WIDTH - ((WIDTH / 10) * 2);
	t->sp = 1;
	if (t->col >= t->line)
		while (sqrt(pow(t->col * t->sp, 2) + pow(t->line * t->sp, 2)) < w)
			t->sp++;
	if (t->col < t->line)
		while (sqrt(pow(t->col * t->sp, 2) + pow(t->line * t->sp, 2)) < h)
			t->sp++;
	t->anglz = 30;
	t->anglx = 30;
	t->angly = 30;
	t->startx = 480;
	t->starty = -480;
	t->deep = 1;
	t->tab = tab;
}

void	ft_img(t_struct *t, char **tab, void *pt_img, char *my_img)
{
	int		bpp;
	int		s_l;
	int		endian;
	int		i;
	int		h;

	h = HEIGHT - (HEIGHT / 9);
	i = WIDTH - ((WIDTH / 10) * 2);
	t->anglx = (t->anglx > 360) ? 360 : t->anglx;
	t->anglx = (t->anglx < -360) ? -360 : t->anglx;
	t->angly = (t->angly > 360) ? 360 : t->angly;
	t->angly = (t->angly < -360) ? -360 : t->angly;
	t->anglz = (t->anglz > 360) ? 360 : t->anglz;
	t->anglz = (t->anglz < -360) ? -360 : t->anglz;
	t->deep = (t->deep > 50) ? 50 : t->deep;
	t->deep = (t->deep < -50) ? -50 : t->deep;
	pt_img = mlx_new_image(t->mlx, i, h);
	my_img = mlx_get_data_addr(pt_img, &(bpp), &(s_l), &(endian));
	t->pt = pt_img;
	t->my = my_img;
	ft_print_map(t, my_img, tab);
	ft_menu4(t);
	mlx_put_image_to_window(t->mlx, t->win, pt_img, 0, HEIGHT / 9);
}

int		main(int argc, char **argv)
{
	t_struct	t;
	void		*pt_img;
	char		*my_img;
	char		**tab;

	if (argc != 2 || !ft_check_fdf2(argv, &t))
	{
		ft_printf("Error : invalid entry.");
		return (0);
	}
	if (!(tab = ft_store(tab, argv, &t)))
	{
		ft_printf(" malloc error : ft_store.");
		return (0);
	}
	t.mlx = mlx_init();
	t.win = mlx_new_window(t.mlx, WIDTH, HEIGHT, "FDF - DeyaNico & Co");
	ft_macros(&t, tab);
	ft_menu(&t, tab, pt_img, argv);
	ft_img(&t, tab, pt_img, my_img);
	mlx_hook(t.win, 2, 0, key_press, &t);
	mlx_hook(t.win, 3, 0, key_release, &t);
	mlx_loop(t.mlx);
	return (0);
}
