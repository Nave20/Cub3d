/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:39:25 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/28 11:39:25 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"


void	load_x_anim(t_all *all, int x, int h, int w)
{
	char	*name;
	char	*tmp;
	t_anim	*anim;

	anim = all->anim;
	tmp = ft_itoa(x + 1);
	{
		//secure
	}
	name = "./assets/animation/rainbow_";
	name = ft_strjoin(name, tmp);
	{
		//secure
	}
	free(tmp);
	name = ft_strjoin(name, ".xpm");
	anim->anim_void[x] = mlx_xpm_file_to_image(all->mlx->mlx_ptr, name,
		&w, &h);
	if (!anim->anim_void[x])
	{
		//error message
	}
	free(name);
	anim->addr[x]->addr = mlx_get_data_addr(anim->anim_void[x], &anim->addr[x]->bpp, &anim->addr[x]->line_length, &anim->addr[x]->endian);
	if (!anim->addr[x]->addr)
	{
		//err
	}
	anim->addr[x]->bpp = anim->addr[x]->bpp / 8;
	anim->frame_height[x] = h;
	anim->frame_width[x] = w;
}

void	load_anim(t_all *all)
{
	int	i;

	i = 0;
	all->anim = malloc(sizeof(t_anim));
	all->anim->addr = malloc(7 * sizeof(t_addr *));
	all->anim->frame_height = malloc(7 * sizeof(int));
	all->anim->frame_width = malloc(7 * sizeof(int));
	all->anim->anim_frame = 0;
	while (i < 7)
	{
		all->anim->addr[i] = malloc(sizeof(t_addr));
		load_x_anim(all, i, 0, 0);
		i++;
	}
}
