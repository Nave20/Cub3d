/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:36:20 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/12 12:01:55 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	valid_xpm(char *line)
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

static int	color_components(t_all *all, char **line, int i, int j)
{
	while (line[i])
		i++;
	if (i != 3)
	{
		free_double_tab(line);
		ft_putendl_fd(RED"Error\n -> too many color components"RESET, 2);
		exit_game(all);
	}
	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] < '0' || line[i][j] > '9')
			{
				free_double_tab(line);
				error_exit(RED"Error\n -> color components "
					"must be numeric"RESET, all, NULL);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	color_range(t_all *all, t_color *color)
{
	if (color->r < 0 || color->r > 255)
	{
		ft_putendl_fd(RED"Error\n -> color must be in "
			"range of [0 - 255]"RESET, 2);
		exit_game(all);
	}
	if (color->g < 0 || color->g > 255)
	{
		ft_putendl_fd(RED"Error\n -> color must be in "
			"range of [0 - 255]"RESET, 2);
		exit_game(all);
	}
	if (color->b < 0 || color->b > 255)
	{
		ft_putendl_fd(RED"Error\n -> color must be in "
			"range of [0 - 255]"RESET, 2);
		exit_game(all);
	}
	return (0);
}

static void	valid_color(t_all *all, t_color *color, int i, char **tmp)
{
	while (color->color[i])
	{
		if (color->color[i] == ' ' || color->color[i] == '\t'
			|| color->color[i] == '\n')
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
		err_split(all);
	color_components(all, tmp, 0, 0);
	color->r = ft_atoi(tmp[0]);
	color->g = ft_atoi(tmp[1]);
	color->b = ft_atoi(tmp[2]);
	free_double_tab(tmp);
	color_range(all, color);
}

void	arg_validation(t_all *all, t_texture *texture)
{
	if (valid_xpm(texture->north_texture))
		return (wrong_format(all));
	if (valid_xpm(texture->south_texture))
		return (wrong_format(all));
	if (valid_xpm(texture->west_texture))
		return (wrong_format(all));
	if (valid_xpm(texture->east_texture))
		return (wrong_format(all));
	valid_color(all, texture->floor_color, 0, NULL);
	valid_color(all, texture->ceiling_color, 0, NULL);
}
