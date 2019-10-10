/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:12:18 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/16 20:01:32 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_num_fdf2(char *buf, int *i, int *k)
{
	int		j;

	j = *i;
	while (buf[*i])
	{
		if (buf[*i] != ' ' && buf[*i] != '\t')
		{
			*i = j;
			break ;
		}
		*i += 1;
	}
	if (buf[*i] == '\0'
	|| ((buf[*i] == ' ' || buf[*i] == '\t') && buf[*i + 1] == '\0'))
	{
		if (*k != 0)
			return (0);
	}
	else
		*i += 1;
	return (1);
}

int		ft_num_fdf(char *buf, int *i, int *k)
{
	char	vir;

	vir = 'n';
	*k -= 1;
	while (buf[*i] != ' ' && buf[*i] != '\t' && buf[*i])
	{
		if (!((buf[*i] >= '0' && buf[*i] <= '9') || buf[*i] == ','
		|| buf[*i] == 'x' || buf[*i] == '-' || buf[*i] == 'X' || buf[*i] == '\n'
		|| (buf[*i] >= 'A' && buf[*i] <= 'F') || buf[*i] == (char)127
		|| (buf[*i] >= 'a' && buf[*i] <= 'f')))
			return (0);
		if ((((buf[*i] >= 'A' && buf[*i] <= 'F')
		|| buf[*i] == 'X') && vir == 'n')
		|| (((buf[*i] >= 'a' && buf[*i] <= 'f')
		|| buf[*i] == 'x') && vir == 'n'))
			return (0);
		if (buf[*i] == ',')
			vir = 'y';
		if ((buf[*i] == ',' && (buf[*i + 1] != '0'
		|| (buf[*i + 2] != 'x' && buf[*i + 2] != 'X')))
		|| (buf[*i] == ',' && (buf[*i - 1] < '0' || buf[*i - 1] > '9')))
			return (0);
		*i += 1;
	}
	return (ft_num_fdf2(buf, i, k));
}

int		ft_check_fdf(char *buf, t_struct *t)
{
	int		i;
	int		k;
	int		res;

	k = t->col;
	i = 0;
	if (buf[0] != '-' && (buf[0] < '0' || buf[0] > '9') && buf[0] != ' '
	&& buf[0] != '\t')
		return (0);
	while (buf[i])
	{
		while (buf[i] && (buf[i] == ' ' || buf[i] == '\t'))
			i += 1;
		if (!(ft_num_fdf(buf, &i, &k)))
			return (0);
	}
	return (1);
}
