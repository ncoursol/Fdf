/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:02:07 by ncoursol          #+#    #+#             */
/*   Updated: 2019/07/16 14:38:22 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	**ft_store3(char *add, int *i, char **tab, int *count)
{
	int		j;

	j = 0;
	while (add[*i] != ' ' && add[*i] != '\n' && add[*i] != '\0')
	{
		j++;
		*i += 1;
	}
	if (!(tab[*count] = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	tab[*count][j] = '\0';
	*i -= j;
	j = 0;
	while (add[*i] != ' ' && add[*i] != '\n' && add[*i] != '\0')
	{
		tab[*count][j] = add[*i];
		*i += 1;
		j++;
	}
	*count += 1;
	return (tab);
}

char	**ft_store2(char **tab, t_struct *t, char *add, int fd)
{
	int		i;
	int		count;
	char	buf[BUF + 1];

	count = 0;
	i = 0;
	t->ax = 1;
	while ((t->ax = read(fd, buf, BUF)) != 0)
	{
		buf[t->ax] = '\0';
		add = ft_strjoin_f(add, buf, 1);
	}
	while (count != (t->col * t->line))
	{
		if (add[i] == '-' || (add[i] >= '0' && add[i] <= '9'))
			ft_store3(add, &i, tab, &count);
		if (add[i])
			i++;
	}
	free(add);
	return (tab);
}

char	**ft_store(char **tab, char **argv, t_struct *t)
{
	int		fd;
	char	*add;

	fd = open(argv[1], O_RDONLY);
	if (BUF <= 0 || !(add = (char*)malloc(sizeof(char) * (BUF + 1))))
		return (NULL);
	add[BUF] = '\0';
	add[0] = '\0';
	if (!(tab = (char**)malloc(sizeof(char*) * ((t->col * t->line) + 1))))
		return (NULL);
	tab[(t->col * t->line)] = NULL;
	tab = ft_store2(tab, t, add, fd);
	close(fd);
	return (tab);
}
