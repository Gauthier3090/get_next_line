/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:57:23 by gpladet           #+#    #+#             */
/*   Updated: 2019/12/11 15:47:46 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*
** Ajout des librairies pour read, free et malloc
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** Ajout des contantes
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define FD_SIZE 10240

/*
** Prototypes des fonctions
*/

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int		add_value_static(int fd, char **s1, char buffer[BUFFER_SIZE + 1]);

#endif
