/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:02:30 by ncoursol          #+#    #+#             */
/*   Updated: 2019/04/29 13:09:55 by ncoursol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 9999

typedef	struct	s_fd
{
	char	*tab;
	int		fd;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
