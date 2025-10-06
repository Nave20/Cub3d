/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:15:31 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/06 16:15:31 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	strnstr_int(const char *src, const char *tofind, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!tofind[0])
		return (0);
	if (size == 0)
		return (0);
	j = ft_strlen((char *) tofind);
	while (src[i] && i < size)
	{
		if (i + j > size)
			return (0);
		if (ft_strncmp((char *)src + i, tofind, j) == 0)
			return (i);
		i++;
	}
	return (0);
}