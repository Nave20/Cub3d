/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:22:13 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/30 17:27:26 by lpaysant         ###   ########.fr       */
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
	if (texture->addr_d)
		free(texture->addr_d);
	if (texture->addr_txt)
		free(texture->addr_txt);
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

void	free_minimap(t_all *all)
{
	if (all->minimap->image)
		mlx_destroy_image(all->mlx->mlx_ptr, all->minimap->image);
	if (all->minimap->addr)
		free(all->minimap->addr);
	if (all->minimap->f_color)
		free(all->minimap->f_color);
	if (all->minimap->p_color)
		free(all->minimap->p_color);
	if (all->minimap->w_color)
		free(all->minimap->w_color);
	if (all->minimap->n_color)
		free(all->minimap->n_color);
	if (all->minimap->c_color)
		free(all->minimap->c_color);
	free(all->minimap);
}

int	exit_game(t_all *all)
{
	if (all->data)
		free_data(all->data);
	if (all->minimap)
		free_minimap(all);
	if (all->texture)
		free_texture(all->texture);
	if (all->key)
		free(all->key);
	if (all->mouse)
		free(all->mouse);
	if (all->anim)
		free_anim(all);
	if (all->mlx)
		free_mlx(all->mlx);
	free(all);
	exit(errno);
	return (0);
}
