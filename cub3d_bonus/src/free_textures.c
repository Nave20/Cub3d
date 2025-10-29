/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:27:00 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/29 16:29:44 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	anim_void_error(t_all *all, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		mlx_destroy_image(all->mlx->mlx_ptr, all->anim->anim_void[i]);
		all->anim->anim_void[i] = NULL;
		i++;
	}
}

void	free_anim(t_all *all)
{
	int	i;

	i = 0;
	if (all->anim->frame_height)
		free(all->anim->frame_height);
	if (all->anim->frame_width)
		free(all->anim->frame_width);
	if (all->anim->addr)
	{
		while (all->anim->addr[i])
		{
			free(all->anim->addr[i]);
			i++;
		}
		free(all->anim->addr);
	}
	i = 0;
	if (all->anim->anim_void[0])
	{
		while (i < 7)
			mlx_destroy_image(all->mlx->mlx_ptr, all->anim->anim_void[i++]);
	}
	free(all->anim);
}

void	free_texture(t_texture *texture)
{
	if (texture->east_texture)
		free(texture->east_texture);
	if (texture->north_texture)
		free(texture->north_texture);
	if (texture->south_texture)
		free(texture->south_texture);
	if (texture->west_texture)
		free(texture->west_texture);
	if (texture->door_texture)
		free(texture->door_texture);
	if (texture->floor_color)
	{
		if (texture->floor_color->color)
			free(texture->floor_color->color);
		free(texture->floor_color);
	}
	if (texture->ceiling_color)
	{
		if (texture->ceiling_color->color)
			free(texture->ceiling_color->color);
		free(texture->ceiling_color);
	}
	free_addr(texture);
	free(texture);
}
