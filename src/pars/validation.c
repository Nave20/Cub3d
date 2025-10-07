/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:36:20 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/07 12:36:20 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	valid_xpm(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		{
			line[i] = 0;
			break ;
		}
		i++;
	}
	tmp = ft_strnstr(line, ".xpm", ft_strlen(line));
	if (!tmp)
		return (1);
	if (tmp[4] != 0)
		return (1);
	return (0);
}

int	color_components(char **line)
{
	int i;
	int j;

	i = 0;
	while (line[i])
		i++;
	if (i != 3)
	{
		perror(RED"Error\n -> too many color components"RESET);
		return (1);
	}
	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] < '0' || line[i][j] > '9')
			{
				perror(RED"Error\n -> color components must be numeric"RESET);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	color_range(t_color *color)
{
	if (color->r < 0 || color->r > 255)
	{
		perror(RED"Error\n -> color must be in range of [0 - 255]"RESET);
		return (1);
	}
	if (color->g < 0 || color->g > 255)
	{
		perror(RED"Error\n -> color must be in range of [0 - 255]"RESET);
		return (1);
	}
	if (color->b < 0 || color->b > 255)
	{
		perror(RED"Error\n -> color must be in range of [0 - 255]"RESET);
		return (1);
	}
	return (0);
}

int	valid_color(t_color *color)
{
	int		i;
	char	**tmp;

	i = 0;
	while (color->color[i])
	{
		if (color->color[i] == ' ' || color->color[i] == '\t' || color->color[i] == '\n')
		{
			color->color[i] = 0;
			break ;
		}
		i++;
	}
	tmp = ft_split(color->color, ',');
	free(color->color);
	color->color = NULL;
	if (!tmp)
		return (err_split());
	if (color_components(tmp))
		return (free_double_tab(tmp));
	color->r = ft_atoi(tmp[0]);
	color->g = ft_atoi(tmp[1]);
	color->b = ft_atoi(tmp[2]);
	free_double_tab(tmp);
	if (color_range(color))
		return (1);
	return (0);
}

int	arg_validation(t_texture *texture)
{
	if (valid_xpm(texture->north_texture))
		return (wrong_format());
	if (valid_xpm(texture->south_texture))
		return (wrong_format());
	if (valid_xpm(texture->west_texture))
		return (wrong_format());
	if (valid_xpm(texture->east_texture))
		return (wrong_format());
	if (valid_color(texture->floor_color))
		return (1);
	if (valid_color(texture->ceiling_color))
		return (1);
	return (0);
}