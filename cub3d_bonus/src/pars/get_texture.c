/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:56:53 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/29 13:26:26 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	get_no(int fd, t_all *all, char *line)
{
	int	i;
	int	error;

	error = 0;
	while (line && ft_strnstr(line, "NO ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl(all));
	}
	if (line)
	{
		i = strnstr_int(line, "NO ", ft_strlen(line));
		i += 3;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		all->texture->valid_north = true;
		all->texture->north_texture = ft_strdup(&line[i]);
		if (!all->texture->north_texture)
			return (err_strdup(all));
		return (0);
	}
	return (1);
}

int	get_so(int fd, t_all *all, char *line)
{
	int	i;
	int	error;

	error = 0;
	while (line && ft_strnstr(line, "SO ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl(all));
	}
	if (line)
	{
		i = strnstr_int(line, "SO ", ft_strlen(line));
		i += 3;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		all->texture->valid_south = true;
		all->texture->south_texture = ft_strdup(&line[i]);
		if (!all->texture->south_texture)
			return (err_strdup(all));
		return (0);
	}
	return (1);
}

int	get_we(int fd, t_all *all, char *line)
{
	int	i;
	int	error;

	error = 0;
	while (line && ft_strnstr(line, "WE ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl(all));
	}
	if (line)
	{
		i = strnstr_int(line, "WE ", ft_strlen(line));
		i += 3;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		all->texture->valid_west = true;
		all->texture->west_texture = ft_strdup(&line[i]);
		if (!all->texture->west_texture)
			return (err_strdup(all));
		return (0);
	}
	return (1);
}

int	get_ea(int fd, t_all *all, char *line)
{
	int	i;
	int	error;

	error = 0;
	while (line && ft_strnstr(line, "EA ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl(all));
	}
	if (line)
	{
		i = strnstr_int(line, "EA ", ft_strlen(line));
		i += 3;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		all->texture->valid_east = true;
		all->texture->east_texture = ft_strdup(&line[i]);
		if (!all->texture->east_texture)
			return (err_strdup(all));
		return (0);
	}
	return (1);
}

int	get_do(int fd, t_all *all, char *line)
{
	int	i;
	int	error;

	error = 0;
	while (line && ft_strnstr(line, "DO ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl(all));
	}
	if (line)
	{
		i = strnstr_int(line, "DO ", ft_strlen(line));
		i += 3;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		all->texture->valid_door = true;
		all->texture->door_texture = ft_strdup(&line[i]);
		if (!all->texture->door_texture)
			return (err_strdup(all));
		return (0);
	}
	return (1);
}
