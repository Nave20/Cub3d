/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:49:12 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/30 17:27:16 by lpaysant         ###   ########.fr       */
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
	if (mlx->d_texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->d_texture);
	if (mlx->fc_image)
		mlx_destroy_image(mlx->mlx_ptr, mlx->fc_image);
	if (mlx->txt_texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->txt_texture);
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
