/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:27:36 by ncoursol          #+#    #+#             */
/*   Updated: 2019/09/14 19:50:15 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_buttons(t_struct *t, int y, char *b1, char *b2)
{
	int		j;
	int		size;

	size = WIDTH - ((WIDTH / 10) * 2) + 30;
	j = size;
	while (j != size + 40)
	{
		mlx_pixel_put(t->mlx, t->win, j, y, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, j, y + 40, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, j + 60, y, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, j + 60, y + 40, 0x6F6F6F);
		j++;
	}
	j = y;
	while (j != y + 40)
	{
		mlx_pixel_put(t->mlx, t->win, size, j, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, size + 40, j, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, size + 60, j, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, size + 100, j, 0x6F6F6F);
		j++;
	}
	mlx_string_put(t->mlx, t->win, size + 15, y + 8, 0xBDBDBD, b1);
	mlx_string_put(t->mlx, t->win, size + 75, y + 8, 0xBDBDBD, b2);
}

void	ft_menu4(t_struct *t)
{
	int		i;
	int		j;
	char	*k;

	j = HEIGHT / 6;
	i = (WIDTH - ((WIDTH / 10) * 2) + 30) + 50;
	k = ft_itoa(t->anglx);
	mlx_string_put(t->mlx, t->win, i, j + 60, 0xBDBDBD, k);
	free(k);
	k = ft_itoa(t->angly);
	mlx_string_put(t->mlx, t->win, i, j * 2 + 60, 0xBDBDBD, k);
	free(k);
	k = ft_itoa(t->anglz);
	mlx_string_put(t->mlx, t->win, i, j * 3 + 60, 0xBDBDBD, k);
	free(k);
	k = ft_itoa(t->deep);
	mlx_string_put(t->mlx, t->win, i, j * 4 + 60, 0xBDBDBD, k);
	free(k);
	k = ft_itoa(t->sp);
	mlx_string_put(t->mlx, t->win, i, j * 5 + 60, 0xBDBDBD, k);
	free(k);
}

void	ft_menu3(t_struct *t, char **argv)
{
	int		i;
	int		j;
	int		k;

	k = HEIGHT / 50;
	i = HEIGHT / 30;
	j = WIDTH - ((WIDTH / 10) * 2) + 30;
	mlx_string_put(t->mlx, t->win, WIDTH / 18, 2, 0xBDBDBD, "Contributors :");
    :x
	mlx_string_put(t->mlx, t->win, WIDTH / 13, i + 20, 0xBDBDBD, "NCoursol");
	mlx_string_put(t->mlx, t->win, WIDTH / 3, k, 0xBDBDBD, "Argv[0] : ");
	mlx_string_put(t->mlx, t->win, WIDTH / 3, i + 20, 0xBDBDBD, "Map Path : ");
	mlx_string_put(t->mlx, t->win, WIDTH / 2.2, k, 0xBDBDBD, argv[0]);
	mlx_string_put(t->mlx, t->win, WIDTH / 2.2, i + 20, 0xBDBDBD, argv[1]);
	i = HEIGHT / 6;
	mlx_string_put(t->mlx, t->win, j, i - 30, 0xBDBDBD, "Rotate X :");
	mlx_string_put(t->mlx, t->win, j, i * 2 - 30, 0xBDBDBD, "Rotate Y :");
	mlx_string_put(t->mlx, t->win, j, i * 3 - 30, 0xBDBDBD, "Rotate Z :");
	mlx_string_put(t->mlx, t->win, j, i * 4 - 30, 0xBDBDBD, "Deep :");
	mlx_string_put(t->mlx, t->win, j, i * 5 - 30, 0xBDBDBD, "Zoom :");
	ft_buttons(t, HEIGHT / 6, "v", "^");
	ft_buttons(t, (HEIGHT / 6) * 2, "<", ">");
	ft_buttons(t, (HEIGHT / 6) * 3, "1", "2");
	ft_buttons(t, (HEIGHT / 6) * 4, "/", "*");
	ft_buttons(t, (HEIGHT / 6) * 5, "+", "-");
}

void	ft_menu2(t_struct *t)
{
	int		i;

	i = 0;
	while (i != WIDTH)
	{
		mlx_pixel_put(t->mlx, t->win, i, (HEIGHT / 9) - 2, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, i, (HEIGHT / 9) - 1, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, i, (HEIGHT / 9), 0x171717);
		i++;
	}
	i = HEIGHT / 9;
	while (i != HEIGHT)
	{
		mlx_pixel_put(t->mlx, t->win, WIDTH - ((WIDTH / 10) * 2), i, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, WIDTH - ((WIDTH / 10) * 2) + 1, i,
				0x6F6F6F);
		i++;
	}
	i = 0;
	while (i != HEIGHT / 9)
	{
		mlx_pixel_put(t->mlx, t->win, WIDTH / 4, i, 0x6F6F6F);
		mlx_pixel_put(t->mlx, t->win, WIDTH / 4 + 1, i, 0x6F6F6F);
		i++;
	}
}

void	ft_menu(t_struct *t, char **tab, char *pt_img, char **argv)
{
	int		i;
	int		j;

	i = 0;
	(void)argv;
	while (i != WIDTH)
	{
		j = 0;
		while (j != HEIGHT)
		{
			mlx_pixel_put(t->mlx, t->win, i, j, 0x232323);
			j++;
		}
		i++;
	}
	j = HEIGHT / 6;
	i = WIDTH - ((WIDTH / 10) * 2) + 30;
	ft_menu2(t);
	ft_menu3(t, argv);
	mlx_string_put(t->mlx, t->win, i, j + 60, 0xBDBDBD, "X : ");
	mlx_string_put(t->mlx, t->win, i, j * 2 + 60, 0xBDBDBD, "Y : ");
	mlx_string_put(t->mlx, t->win, i, j * 3 + 60, 0xBDBDBD, "Z : ");
	mlx_string_put(t->mlx, t->win, i, j * 4 + 60, 0xBDBDBD, "D : ");
	mlx_string_put(t->mlx, t->win, i, j * 5 + 60, 0xBDBDBD, "S : ");
}
