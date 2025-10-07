/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:56:53 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/06 13:56:53 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	get_no(int fd, t_texture *texture, char *line)
{
	int	i;
	int error;

	error = 0;
	while (line && ft_strnstr(line, "NO ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl());
	}
	if (line)
	{
		i = strnstr_int(line, "NO ", ft_strlen(line));
		i += 3;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		texture->valid_north = true;
		texture->north_texture = ft_strdup(&line[i]);
		if (!texture->north_texture)
			return (err_strdup());
		return (0);
	}
	return (1);
}

int	get_so(int fd, t_texture *texture, char *line)
{
	int	i;
	int error;

	error = 0;
	while (line && ft_strnstr(line, "SO ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl());
	}
	if (line)
	{
		i = strnstr_int(line, "SO ", ft_strlen(line));
		i += 3;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		texture->valid_south = true;
		texture->south_texture = ft_strdup(&line[i]);
		if (!texture->south_texture)
			return (err_strdup());
		return (0);
	}
	return (1);
}

int	get_we(int fd, t_texture *texture, char *line)
{
	int	i;
	int error;

	error = 0;
	while (line && ft_strnstr(line, "WE ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl());
	}
	if (line)
	{
		i = strnstr_int(line, "WE ", ft_strlen(line));
		i += 3;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		texture->valid_west = true;
		texture->west_texture = ft_strdup(&line[i]);
		if (!texture->west_texture)
			return (err_strdup());
		return (0);
	}
	return (1);
}

int	get_ea(int fd, t_texture *texture, char *line)
{
	int	i;
	int error;

	error = 0;
	while (line && ft_strnstr(line, "EA ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl());
	}
	if (line)
	{
		i = strnstr_int(line, "EA ", ft_strlen(line));
		i += 3;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		texture->valid_east = true;
		texture->east_texture = ft_strdup(&line[i]);
		if (!texture->east_texture)
			return (err_strdup());
		return (0);
	}
	return (1);
}
