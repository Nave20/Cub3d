/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:59:30 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/09 12:08:46 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	char_check(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= data->lines)
	{
		while (j <= data->cols)
		{
			if (!is_good_char(data->map[i][j]) && data->map[i][j] != ' ')
				error_exit("Error\nOne or several unauthorized character\n",
					NULL, data);
			j++;
		}
		j = 0;
		i++;
	}
}

bool	is_invalid_char(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

bool	is_player(char c)
{
	if(c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

void	player_check(t_data *data)
{
	int	i;
	int	j;
	int	nbplayer;

	i = 1;
	j = 1;
	nbplayer = 0;
	while(i <= data->lines)
	{
		while(j <= data->cols)
		{
			if(is_player(data->map[i][j]))
				nbplayer++;
			j++;
		}
		j = 1;
		i++;
	}
	if(nbplayer != 1)
		error_exit("Error\nThere must be exactly one player in the map\n",
			NULL, data);
}

void	map_parsing(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	char_check(data);
	while (i <= data->lines)
	{
		while (j <= data->cols)
		{
			if (data->map[i][j] == ' ' && (is_invalid_char(data->map[i + 1][j])
			|| is_invalid_char(data->map[i - 1][j])
			|| is_invalid_char(data->map[i][j + 1])
			|| is_invalid_char(data->map[i][j - 1])))
				error_exit("Error\nMap must be surrounded by walls\n",
					NULL, data);
			j++;
		}
		j = 1;
		i++;
	}
	player_check(data);
}
