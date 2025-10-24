/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:22:13 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/24 10:30:52 by lpaysant         ###   ########.fr       */
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
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->win_ptr = NULL;
	if (mlx->mlx_ptr)
	{
		mlx_loop_end(mlx->mlx_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
	free(mlx);
}

void	free_addr(t_texture *texture)
{
	if (texture->addr_e)
		free(texture->addr_e);
	if (texture->addr_n)
		free(texture->addr_n);
	if (texture->addr_s)
		free(texture->addr_s);
	if (texture->addr_w)
		free(texture->addr_w);
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

void	free_data(t_data *data)
{
	if (data->map)
		free_map_tab(data->map);
	if (data->ray)
		free(data->ray);
	if (data->player)
		free(data->player);
	if (data->render)
		free(data->render);
	free(data);
}

int	exit_game(t_all *all)
{
	printf("ray : %f\n", all->data->player->radian);
	printf("pos_x : %f\n", all->data->player->pos_x);
	printf("pos_y : %f\n", all->data->player->pos_y);
	if (all->data)
		free_data(all->data);
	if (all->minimap)
	{
		free_map_tab(all->minimap->map);
		if (all->minimap->image)
			mlx_destroy_image(all->mlx->mlx_ptr, all->minimap->image);
		free(all->minimap);
	}
	if (all->mlx)
		free_mlx(all->mlx);
	if (all->texture)
		free_texture(all->texture);
	if(all->key)
		free(all->key);
	if (all->mouse)
		free(all->mouse);
	free(all);
	exit(0);
	return (0);
}
