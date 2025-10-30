/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:22:13 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/29 17:21:39 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

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
	if (all->data)
		free_data(all->data);
	if (all->mlx)
		free_mlx(all->mlx);
	if (all->texture)
		free_texture(all->texture);
	if (all->key)
		free(all->key);
	free(all);
	exit(0);
	return (0);
}
