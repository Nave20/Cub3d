/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:39:25 by vpirotti          #+#    #+#             */
/*   Updated: 2025/10/29 16:30:15 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

char	*get_anim_file_name(t_all *all, int x)
{
	char	*name;
	char	*tmp;

	tmp = ft_itoa(x + 1);
	if (!tmp)
		error_exit("Error\nMalloc failure\n", all, NULL);
	name = ft_strjoin("./assets/animation/rainbow_", tmp);
	free(tmp);
	if (!name)
		error_exit("Error\nMalloc failure\n", all, NULL);
	tmp = name;
	name = ft_strjoin(tmp, ".xpm");
	free(tmp);
	if (!name)
		error_exit("Error\nMalloc failure\n", all, NULL);
	return (name);
}

void	load_x_anim(t_all *all, int x, int h, int w)
{
	char	*name;
	t_anim	*anim;

	anim = all->anim;
	name = get_anim_file_name(all, x);
	anim->anim_void[x] = mlx_xpm_file_to_image(all->mlx->mlx_ptr, name,
			&w, &h);
	if (!anim->anim_void[x])
	{
		free(name);
		anim_void_error(all, x);
		error_exit("Error\nXpm to image failure\n", all, NULL);
	}
	free(name);
	anim->addr[x]->addr = mlx_get_data_addr(anim->anim_void[x],
			&anim->addr[x]->bpp, &anim->addr[x]->line_length,
			&anim->addr[x]->endian);
	if (!anim->addr[x]->addr)
	{
		anim_void_error(all, x + 1);
		error_exit("Error\nGet data addr failure\n", all, NULL);
	}
	anim->addr[x]->bpp = anim->addr[x]->bpp / 8;
	anim->frame_height[x] = h;
	anim->frame_width[x] = w;
}

void	init_anim_struct(t_all *all)
{
	all->anim = ft_calloc(1, sizeof(t_anim));
	if (!all->anim)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->anim->addr = ft_calloc(8, sizeof(t_addr *));
	if (!all->anim->addr)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->anim->frame_height = malloc(7 * sizeof(int));
	if (!all->anim->frame_height)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->anim->frame_width = malloc(7 * sizeof(int));
	if (!all->anim->frame_width)
		error_exit("Error\nMalloc failure\n", all, NULL);
	all->anim->anim_frame = 0;
}

void	load_anim(t_all *all)
{
	int	i;

	i = 0;
	init_anim_struct(all);
	all->anim->anim_frame = 0;
	while (i < 7)
	{
		all->anim->addr[i] = malloc(sizeof(t_addr));
		if (!all->anim->addr[i])
		{
			anim_void_error(all, i);
			error_exit("Error\nMalloc failure\n", all, NULL);
		}
		load_x_anim(all, i, 0, 0);
		i++;
	}
}
