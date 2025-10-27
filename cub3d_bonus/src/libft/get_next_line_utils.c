/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:30:49 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/07 14:38:48 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_tabs(char *buffer, char **buffrest, char *line)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	if (*buffrest)
	{
		free(*buffrest);
		*buffrest = NULL;
		buffrest = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strcpy_gnl(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*read_buffer(int fd, char **buffrest, int *error)
{
	int		nbread;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		*error = 1;
		return (NULL);
	}
	if (!*buffrest)
	{
		nbread = read(fd, buffer, BUFFER_SIZE);
		if (nbread <= 0)
			return (free(buffer), NULL);
		buffer[nbread] = '\0';
	}
	else
	{
		buffer = ft_strcpy_gnl(buffer, *buffrest);
		free(*buffrest);
		*buffrest = NULL;
	}
	return (buffer);
}
