/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:45:35 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/10/24 15:47:26 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *cleanup_crew(int fd, char **stash)
{
    int     i;
    char    *temp;
    char    *line;
    
    i = 0;
    // ab(\n)cd
    while (stash[fd][i] != '\n' && stash[fd][i])
        i++;
    if (stash[fd][i] == '\n')
    {
        line = ft_substr(stash[fd], 0, i);
        temp = ft_substr(stash[fd], i + 1, ft_strlen(stash[fd]) - i - 1);
        free(stash[fd]);
        stash[fd] = temp;
        return (line);
    }
    else
    {
        line = ft_strdup(stash[fd]);
        free(stash[fd]);
        stash[fd] = NULL;
        return (line);
    }
}

char    *get_next_line(int fd)
{
    int             readchard;
    char            buffer[BUFFER_SIZE + 1];
    char            *temp;
    static char     *stash[4096];

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    readchard = 0;
    while ((readchard = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[readchard] = '\0';
        if (!stash[fd])
            stash[fd] = ft_strdup(""); 
        temp = ft_strjoin(stash[fd], buffer);
        free(stash[fd]);
        stash[fd] = temp;
        if (ft_strchr(stash[fd], '\n'))
            break;
    }
    if (!stash[fd] || readchard < 0)
        return (NULL);
    return (cleanup_crew(fd, stash));
}

int main()
{
    int     fd;
    char    *str;
    FILE    *file;

    file = fopen("testfile.txt", "r");
    fd = fileno(file);
    while (str = get_next_line(fd))
        printf("%s\n", str);
    return (0);
}