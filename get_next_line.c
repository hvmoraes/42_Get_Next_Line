/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:52:46 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/10/25 10:34:53 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line(int fd, char **matrix)
{
	int		i;
	char	*temp;
	char	*result;

	i = 0;
	while (matrix[fd][i] != '\n' && matrix[fd][i])
		i++;
	if (matrix[fd][i] == '\n')
	{
		result = ft_substr(matrix[fd], 0, i);
		temp = ft_substr(matrix[fd], i + 1, ft_strlen(matrix[fd]) - i - 1);
		free(matrix[fd]);
		matrix[fd] = temp;
		return (result);
	}
	else
	{
		result = ft_strdup(matrix[fd]);
		free(matrix[fd]);
		matrix[fd] = NULL;
		return (result);
	}
}

char	*get_next_line(int fd)
{
	int			i;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	static char	*matrix[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = read(fd, buffer, BUFFER_SIZE);
	while (i > 0)
	{
		buffer[i] = '\0';
		if (!matrix[fd])
			matrix[fd] = ft_strdup("");
		temp = ft_strjoin(matrix[fd], buffer);
		free(matrix[fd]);
		matrix[fd] = temp;
		if (ft_strchr(matrix[fd], '\n'))
			break ;
		i = read(fd, buffer, BUFFER_SIZE);
	}
	if (!matrix[fd] || i < 0)
		return (NULL);
	return (line(fd, matrix));
}

int main()
{
    int     fd;
    char    *str;
    FILE    *file;

    file = fopen("test.txt", "r");
    fd = fileno(file);
    while ((str = get_next_line(fd)))
        printf("%s\n", str);
    return (0);
}