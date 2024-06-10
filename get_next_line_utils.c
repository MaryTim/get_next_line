/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudkevi <mbudkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:55:52 by mbudkevi          #+#    #+#             */
/*   Updated: 2024/03/22 18:18:30 by mbudkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	if (c == '\0')
		return ((char *)&s[ft_strlen((char *)s)]);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc(ft_strlen((char *)s1) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (0);
	if (start > (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > (size_t)ft_strlen((char *)s + start))
		len = ft_strlen((char *)s + start);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *)malloc(ft_strlen((char *)(s1)) + ft_strlen((char *)(s2)) + 1);
	if (!res)
		return (0);
	while ((s1)[i])
	{
		res[i] = (s1)[i];
		i++;
	}
	while ((s2)[j])
	{
		res[i] = (s2)[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
