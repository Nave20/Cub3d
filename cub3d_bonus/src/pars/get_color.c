/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:50:16 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/06 17:50:16 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	get_f(int fd, t_texture *texture, char *line)
{
	int	i;
	int	error;

	error = 0;
	while (line && ft_strnstr(line, "F ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl());
	}
	if (line)
	{
		i = strnstr_int(line, "F ", ft_strlen(line));
		i += 2;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		texture->valid_floor = true;
		texture->floor_color->color = ft_strdup(&line[i]);
		if (!texture->floor_color->color)
			return (err_strdup());
		return (0);
	}
	return (1);
}

int	get_c(int fd, t_texture *texture, char *line)
{
	int	i;
	int	error;

	error = 0;
	while (line && ft_strnstr(line, "C ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl());
	}
	if (line)
	{
		i = strnstr_int(line, "C ", ft_strlen(line));
		i += 2;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		texture->valid_ceiling = true;
		texture->ceiling_color->color = ft_strdup(&line[i]);
		if (!texture->ceiling_color->color)
			return (err_strdup());
		return (0);
	}
	return (1);
}
