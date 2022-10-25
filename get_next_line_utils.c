/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:23:31 by hcorrea-          #+#    #+#             */
/*   Updated: 2022/10/25 10:41:18 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	while (i < len && i < ft_strlen(str))
	{
		result[i] = str[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;

	i = 0;
	result = (char *)malloc(ft_strlen(s1) + 1);
	if (!result || !s1)
		return (0);
	while (i < ft_strlen(s1) + 1 && ((char *)result)[i] && ((char *)s1)[i])
	{
		((unsigned char *)result)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	if (!(s1 || s2))
		return (0);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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

char	*ft_strchr(const char *str, int c)
{
	while (str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (0);
}
