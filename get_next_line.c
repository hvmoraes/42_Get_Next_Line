/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:52:46 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/11/14 16:03:32 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*line(char **matrix, int fd)
{
	int		i;
	char	*result;
	char	*temp;

	i = 0;
	result = malloc((ft_strlen((char *)matrix[fd])
				- ft_strlen(ft_strchr(matrix[fd], '\n')) + 2));
	temp = &matrix[fd][ft_strlen((char *)matrix[fd])
		- ft_strlen(ft_strchr(matrix[fd], '\n')) + 1];
	i = 0;
	while (matrix[fd][i] && matrix[fd][i] != '\n')
	{
		result[i] = matrix[fd][i];
		i++;
	}
	result[i++] = '\n';
	result[i] = '\0';
	free(matrix[fd]);
	matrix[fd] = temp;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*matrix[FOPEN_MAX];
	char		*buff;
	int			rd;

	buff = malloc(BUFFER_SIZE - 1);
	rd = read(fd, buff, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE < 0 || fd > FOPEN_MAX || rd < 0 || !buff)
		return (NULL);
	if (!matrix[fd])
		matrix[fd] = ft_strdup("");
	while (rd > 0)
	{
		matrix[fd] = ft_strjoin(matrix[fd], buff);
		rd = read(fd, buff, BUFFER_SIZE);
		if (ft_strchr(matrix[fd], '\n'))
			break ;
	}
	return (line(matrix, fd));
}

int	main(void)
{
	int		fd;

	fd = open("get_next_line.c", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
