/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:23:31 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/11/14 15:30:40 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	if (!(s1 || s2))
		return (0);
	result = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!result)
		return (0);
	j = 0;
	while (s1[i])
	{
		result[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *str)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(ft_strlen((char *)str) + 1);
	if (!result || !str)
		return (0);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (!str)
		return (0);
	if (start >= ft_strlen((char *)str))
	{
		result = malloc(1);
		if (!result)
			return (0);
		*result = '\0';
		return (result);
	}
	if (len > ft_strlen((char *)str))
		return (ft_strdup((char *)str + start));
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	while (j < len && i < ft_strlen((char *)str))
		result[j++] = str[i++];
	result[j] = '\0';
	return (result);
}
