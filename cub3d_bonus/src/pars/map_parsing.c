/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:59:30 by lpaysant          #+#    #+#             */
/*   Updated: 2025/11/11 12:13:19 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static void	char_check(t_all *all)
{
	int		i;
	int		j;
	char	**tab;

	i = 1;
	j = 1;
	tab = all->data->map;
	while (i <= all->data->lines)
	{
		while (j <= all->data->cols)
		{
			if (!is_good_char(tab[i][j]) && tab[i][j] != ' ')
				error_exit("Error\nOne or several unauthorized character\n",
					all, NULL);
			j++;
		}
		j = 0;
		i++;
	}
}

static void	player_check(t_all *all)
{
	int	i;
	int	j;
	int	nbplayer;

	i = 1;
	j = 1;
	nbplayer = 0;
	while (i <= all->data->lines)
	{
		while (j <= all->data->cols)
		{
			if (is_player(all->data->map[i][j]))
				nbplayer++;
			j++;
		}
		j = 1;
		i++;
	}
	if (nbplayer != 1)
		error_exit("Error\nThere must be exactly one player in the map\n",
			all, NULL);
}

void	map_parsing(t_data *data, t_all *all)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	char_check(all);
	while (i <= data->lines)
	{
		while (j <= data->cols)
		{
			if (data->map[i][j] == ' ' && (is_invalid_char(data->map[i + 1][j])
			|| is_invalid_char(data->map[i - 1][j])
			|| is_invalid_char(data->map[i][j + 1])
			|| is_invalid_char(data->map[i][j - 1])))
				error_exit("Error\nMap must be surrounded by walls\n",
					all, NULL);
			j++;
		}
		j = 1;
		i++;
	}
	player_check(all);
}
