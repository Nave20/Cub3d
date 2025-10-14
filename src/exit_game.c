/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:22:13 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/09 18:23:42 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	destroy_images(t_mlx *mlx)
{
	if (mlx->e_texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->e_texture);
	if (mlx->w_texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->w_texture);
	if (mlx->s_texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->s_texture);
	if (mlx->n_texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->n_texture);
	if (mlx->fc_image)
		mlx_destroy_image(mlx->mlx_ptr, mlx->fc_image);
}

void	free_mlx(t_mlx *mlx)
{
	destroy_images(mlx);
	if (mlx->win_ptr)
		free(mlx->win_ptr);
	mlx->win_ptr = NULL;
	if (mlx->mlx_ptr)
	{
		mlx_loop_end(mlx->mlx_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
}

void	free_texture(t_texture *texture)
{
	if (texture->east_texture)
		free(texture->east_texture);
	if (texture->north_texture)
		free(texture->north_texture);
	if (texture->south_texture)
		free(texture->south_texture);
	if (texture->east_texture)
		free(texture->east_texture);
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
}

int	exit_game(t_all *all)
{
	if (all->data)
	{
		if(all->data->map)
			free_map_tab(all->data->map);
		free(all->data);
	}
	if (all->mlx)
		free(all->mlx);
	if (all->texture)
		free_texture(all->texture);
	free(all);
	exit(0);
	return (0);
}
