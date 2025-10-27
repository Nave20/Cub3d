/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:40:24 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/09 12:48:36 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

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
