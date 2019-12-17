/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 09:58:50 by gpladet           #+#    #+#             */
/*   Updated: 2019/12/11 16:27:00 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** retourne 1 lorsqu'une ligne est lue
** retourne 0 lorsque la derniere ligne est lue
** retourne -1 en cas d'erreur
*/

static int		ft_freestr(char **s1)
{
	if (s1 != NULL)
	{
		free(*s1);
		*s1 = NULL;
	}
	return (0);
}

static int		display_line_complement(char **s1, int i)
{
	char	*tmp;

	if ((*s1)[i])
	{
		if (!(tmp = ft_strdup(&(*s1)[i + 1])))
			return (-1);
		free(*s1);
		if (!(*s1 = ft_strdup(tmp)))
			return (-1);
		free(tmp);
		return (1);
	}
	else
		return (ft_freestr(s1));
}

static int		display_line(char **line, char **s1)
{
	int		i;

	i = 0;
	if ((*s1)[i])
	{
		while ((*s1)[i] != '\0' && (*s1)[i] != '\n')
			i++;
		if (!(*line = ft_substr(*s1, 0, i)))
			return (-1);
		return (display_line_complement(s1, i));
	}
	else
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
}

static int		return_value_line(int fd, char **s1, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	if (ret == 0 && s1[fd] == NULL)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	else
		return (display_line(line, &s1[fd]));
}

int				get_next_line(int fd, char **line)
{
	static char	*s1[FD_SIZE];
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > FD_SIZE)
		return (-1);
	ret = 0;
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!s1[fd])
		{
			if (!(s1[fd] = ft_strdup(buffer)))
				return (-1);
		}
		else
		{
			if (add_value_static(fd, s1, buffer) == -1)
				return (-1);
		}
		if (ft_strchr(s1[fd], '\n'))
			break ;
	}
	return (return_value_line(fd, s1, line, ret));
}
