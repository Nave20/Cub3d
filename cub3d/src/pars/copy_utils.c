/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:53:27 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/29 16:58:57 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	check_file_ending(int fd, t_all *all, char *buffer, t_list *lst)
{
	int	error;

	error = 0;
	if (!buffer)
		return ;
	while (buffer != NULL)
	{
		if (buffer[0] == '\n')
		{
			free(buffer);
			buffer = get_next_line(fd, &error);
			if (error != 0)
				error_exit("Error\nGNL failure\n", all, lst);
		}
		else
		{
			free(buffer);
			error_exit("Error\nMap must be the last element of the .cub file\n",
				all, lst);
		}
	}
}

void	add_last_border_to_tab(t_list *lst, t_all *all, int i)
{
	int	j;

	j = 0;
	all->data->map[i] = ft_calloc(all->data->cols + 5, sizeof(char));
	if (!all->data->map[i])
		error_exit("Error\nMalloc failure\n", all, lst);
	while (j < all->data->cols + 2)
	{
		all->data->map[i][j] = ' ';
		j++;
	}
	j = 0;
	i++;
	all->data->map[i] = ft_calloc(all->data->cols + 5, sizeof(char));
	if (!all->data->map[i])
		error_exit("Error\nMalloc failure\n", all, lst);
	while (j < all->data->cols + 2)
	{
		all->data->map[i][j] = ' ';
		j++;
	}
}

void	add_fist_border_to_tab(t_list *lst, t_all *all)
{
	int	i;

	i = 0;
	all->data->map[0] = ft_calloc(all->data->cols + 5, sizeof(char));
	if (!all->data->map[0])
		error_exit("Error\nMalloc failure\n", all, lst);
	while (i < all->data->cols + 2)
	{
		all->data->map[0][i] = ' ';
		i++;
	}
	i = 0;
	all->data->map[1] = ft_calloc(all->data->cols + 5, sizeof(char));
	if (!all->data->map[1])
		error_exit("Error\nMalloc failure\n", all, lst);
	while (i < all->data->cols + 2)
	{
		all->data->map[1][i] = ' ';
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
