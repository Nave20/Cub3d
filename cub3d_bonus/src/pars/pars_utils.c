/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:15:31 by vpirotti          #+#    #+#             */
/*   Updated: 2025/11/11 12:14:28 by lpaysant         ###   ########.fr       */
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

void	texture_print(t_texture *texture) // a enlever avant de push
{
	if (texture->north_texture)
		printf("North texture : %s\n", texture->north_texture);
	if (texture->south_texture)
		printf("South texture : %s\n", texture->south_texture);
	if (texture->west_texture)
		printf("West texture : %s\n", texture->west_texture);
	if (texture->east_texture)
		printf("East texture : %s\n", texture->east_texture);
	if (texture->floor_color)
		printf("Floor color : %d, %d, %d\n", texture->floor_color->r,
			texture->floor_color->g, texture->floor_color->b);
	if (texture->ceiling_color)
		printf("Ceiling color : %d, %d, %d\n", texture->ceiling_color->r,
			texture->ceiling_color->g, texture->ceiling_color->b);
}
