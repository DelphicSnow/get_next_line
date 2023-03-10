/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:41:46 by tkajanek          #+#    #+#             */
/*   Updated: 2023/03/09 14:55:27 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len ++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = (char *)s;
	if (c == 0)
		return (ptr + ft_strlen(s));
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s, int i)
{
	int		len;
	int		index;
	char	*dest;

	index = 0;
	if (i < ft_strlen (s))
		len = i;
	else
		len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	while (index < len)
	{
		dest[index] = s[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strjoin(char *static_buff, char const *read_buffer)
{
	size_t	len;
	size_t	i;
	char	*joined;

	if (static_buff == NULL)
		static_buff = ft_strdup("", 0);
	if (read_buffer == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(static_buff) + ft_strlen(read_buffer) + 1;
	joined = (char *)malloc(len * sizeof(char));
	if (!joined)
		return (NULL);
	while (static_buff[i])
	{
		joined[i] = static_buff[i];
		i ++;
	}
	while (*read_buffer)
		joined[i++] = *read_buffer++;
	joined[i] = '\0';
	free(static_buff);
	return (joined);
}
