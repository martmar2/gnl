/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:10:13 by martmar2          #+#    #+#             */
/*   Updated: 2024/05/02 11:33:27 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*spc;
	unsigned long	i;

	i = 0;
	spc = malloc(count * size);
	if (!spc)
		return (0);
	while (i < count * size)
	{
		spc[i] = 0;
		i++;
	}
	return ((void *)spc);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*spc;
	size_t	len;

	if (s1 == NULL)
		s1 = ft_calloc(1, 1);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	spc = (char *)ft_calloc(len, 1);
	if (!spc)
		return (0);
	while (s1[i] != 0)
	{
		spc[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		spc[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (spc);
}

char	*ft_strchr(const char *s, int c)
{
	int		cont;

	if (s == NULL)
		return (NULL);
	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == (unsigned char)c)
			return ((char *)&s[cont]);
		cont++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[cont]);
	return (NULL);
}
