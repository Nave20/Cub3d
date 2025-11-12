/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:50:16 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 11:56:15 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	get_f(int fd, t_all *all, char *line)
{
	int	i;
	int	error;

	error = 0;
	while (line && ft_strnstr(line, "F ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl(all));
	}
	if (line)
	{
		i = strnstr_int(line, "F ", ft_strlen(line));
		i += 2;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		all->texture->valid_floor = true;
		all->texture->floor_color->color = ft_strdup(&line[i]);
		if (!all->texture->floor_color->color)
		{
			free(line);
			return (err_strdup(all));
		}
	}
}

void	get_c(int fd, t_all *all, char *line)
{
	int	i;
	int	error;

	error = 0;
	while (line && ft_strnstr(line, "C ", ft_strlen(line)) == NULL)
	{
		line = get_next_line(fd, &error);
		if (error)
			return (err_gnl(all));
	}
	if (line)
	{
		i = strnstr_int(line, "C ", ft_strlen(line));
		i += 2;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		all->texture->valid_ceiling = true;
		all->texture->ceiling_color->color = ft_strdup(&line[i]);
		if (!all->texture->ceiling_color->color)
		{
			free(line);
			return (err_strdup(all));
		}
	}
}
