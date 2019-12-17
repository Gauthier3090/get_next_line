/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:57:29 by gpladet           #+#    #+#             */
/*   Updated: 2019/12/11 15:54:10 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			add_value_static(int fd, char **s1, char buffer[BUFFER_SIZE + 1])
{
	char	*tmp;

	if (!(tmp = ft_strjoin(s1[fd], buffer)))
		return (-1);
	free(s1[fd]);
	if (!(s1[fd] = ft_strdup(tmp)))
		return (-1);
	free(tmp);
	return (2);
}

char		*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	if (!(s2 = malloc(i + 1 * sizeof(char))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char		*ft_strjoin(char *dst, char *src)
{
	char	*s3;
	int		i;
	int		j;

	if (!dst || !src)
		return (NULL);
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	if (!(s3 = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	while (dst[i])
	{
		s3[i] = dst[i];
		i++;
	}
	j = -1;
	while (src[++j])
		s3[i + j] = src[j];
	s3[i + j] = '\0';
	return (s3);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*word;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (start > i)
	{
		if (!(word = malloc(1 * sizeof(char))))
			return (NULL);
		word[0] = '\0';
		return (word);
	}
	if (!(word = malloc(len + 1 * sizeof(char))))
		return (NULL);
	i = 0;
	while ((i < len) && (s[start] != '\0'))
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)s;
	while (word[i] != '\0')
	{
		if (word[i] == c)
			return (&word[i]);
		i++;
	}
	if (word[i] == c)
		return (&word[i]);
	return (NULL);
}
