/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:00:55 by martmar2          #+#    #+#             */
/*   Updated: 2024/05/02 11:53:49 by martmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#include "get_next_line.h"

// Esta funcion lo que va a hacer es coger un string
// y devolver hasta el salto de linea (con malloc)
// por ejemplo:
// str = "hola caracola\nque tal"
// la function devuelve: "hola caracola\n"
char	*jumper(char *str)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	cpy = malloc(i + 1);
	if (!cpy)
		return (NULL);
	while (j < i)
	{
		cpy[j] = str[j];
		j++;
	}
	cpy[j] = 0;
	return (cpy);
}

//la función cleaner va a eliminar el string que
//ya se ha devuelto, dejando solo a partir de \n
//str = "hola\nque tal"
//devuelve: "que tal"

char	*cleaner(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	new_str = malloc(ft_strlen(str) - i + 1);
	if (!new_str)
		return (NULL);
	while (i < ft_strlen(str))
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = 0;
	free(str);
	return (new_str);
}

char	*ft_book(char *storage, int fd)
{
	char	*buff;
	int		r;

	while (ft_strchr(storage, '\n') == NULL)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		r = read(fd, buff, BUFFER_SIZE);
		if (r <= 0 && (r == -1 || (storage == NULL || storage[0] == 0)))
		{
			free(storage);
			storage = NULL;
			return (free(buff), NULL);
		}
		if (r == 0 && (storage != NULL || storage[0] != 0))
		{
			free(buff);
			break ;
		}
		buff[r] = 0;
		storage = ft_strjoin(storage, buff);
		free(buff);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	storage = ft_book(storage, fd);
	if (storage == NULL)
		return (NULL);
	line = jumper(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = cleaner(storage);
	return (line);
}

//int main(void)
//{
//	int fd = open("only_nl.txt", O_RDWR);
//	if (fd == -1)
//		return (1);
//	char* line;
//
//	line = get_next_line(fd);
//	while (line != NULL)
//	{
//		printf("%s", line);
//		free(line);
//		line = get_next_line(fd);
//	}
//	close(fd);
//}
