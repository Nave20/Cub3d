/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:53:27 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/07 17:55:40 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	add_last_border_to_tab(t_list *lst, t_data *data, int i)
{
	int	j;

	j = 0;
	data->map[i] = ft_calloc(data->cols + 3, sizeof(char));
	if (!data->map[i])
		error_exit("Error\nMalloc failure\n", lst, data);
	while (j < data->cols + 1)
	{
		data->map[i][j] = 'X';
		j++;
	}
}

void	add_fist_border_to_tab(t_list *lst, t_data *data)
{
	int	i;

	i = 0;
	data->map[0] = ft_calloc(data->cols + 3, sizeof(char));
	if (!data->map[0])
		error_exit("Error\nMalloc failure\n", lst, data);
	while (i < data->cols + 1)
	{
		data->map[0][i] = 'X';
		i++;
	}
}

void	find_cols_nb_map(t_data *data, t_list *lst)
{
	t_list	*ptr;
	int		col;

	ptr = lst;
	data->cols = 0;
	while (ptr)
	{
		col = ft_strlen(ptr->content);
		if (col > data->cols)
			data->cols = col;
		ptr = ptr->next;
	}
}
