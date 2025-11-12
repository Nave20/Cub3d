/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:40:24 by lpaysant          #+#    #+#             */
/*   Updated: 2025/11/12 11:56:15 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

bool	is_invalid_char(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == 'O' || c == 'C')
		return (1);
	else
		return (0);
}

bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

bool	is_good_char(char c)
{
	if (c && c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W'
		&& c != 'O' && c != 'E' && c != 'C')
		return (0);
	else
		return (1);
}

bool	is_map_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		if (!is_good_char(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}
