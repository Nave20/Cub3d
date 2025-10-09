/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:07:44 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/08 17:44:40 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	fill_line(t_data *data, char *line, int i, int j)
{
	int	i_line;

	i_line = 0;
	while (line[i_line] && line[i_line] != '\n')
	{
		data->map[i][j] = line[i_line];
		j++;
		i_line++;
	}
	while (j < data->cols)
	{
		data->map[i][j] = ' ';
		j++;
	}
	data->map[i][j] = ' ';
}

void	cpy_lst_to_tab(t_list *lst, t_data *data)
{
	t_list	*ptr;
	int		i;
	int		j;

	find_cols_nb_map(data, lst);
	data->lines = ft_lstsize(lst);
	i = 1;
	j = 0;
	ptr = lst;
	data->map = ft_calloc(data->lines + 3, sizeof(char *));
	if(!data->map)
		error_exit("Error\nMalloc failure", lst, data);
	add_fist_border_to_tab(lst, data);
	while (ptr != NULL)
	{
		data->map[i] = ft_calloc(data->cols + 3, sizeof(char));
		if(!data->map[i])
			error_exit("Error\nMalloc failure", lst, data);
		data->map[i][j++] = ' ';
		fill_line(data, ptr->content, i, j);
		i++;
		j = 0;
		ptr = ptr->next;
	}
	add_last_border_to_tab(lst, data, i);
}

t_list	*cpy_map_to_lst(t_data *data, char *buffer, int fd, int error)
{
	t_list	*ptr;
	t_list	*lst;

	lst = NULL;
	while (is_map_line(buffer))
	{
		ptr = ft_lstnew(buffer);
		if (!ptr)
			error_exit("Error\nft_lstnew failure\n", lst, data);
		ft_lstadd_back(&lst, ptr);
		buffer = get_next_line(fd, &error);
		if (error != 0)
			error_exit("Error\nGNL failure\n", lst, data);
	}
	if (buffer)
		check_file_ending(fd, data, buffer, lst);
	return (lst);
}

void	map_handling(char *buffer, int fd, t_data *data, t_list *lst)
{
	int	error;

	error = 0;
	if (buffer && is_map_line(buffer))
	{
		lst = cpy_map_to_lst(data, buffer, fd, error);
		cpy_lst_to_tab(lst, data);
		free_lst(lst);
		print_map(data->map);
		return ;
	}
	else
	{
		free(buffer);
		error_exit("Error\nThere are no requested characters for the map\n ",
			NULL, data);
	}
}

void	find_map(int fd, t_data *data)
{
	char	*buffer;
	t_list	*lst;
	int		error;

	lst = NULL;
	buffer = get_next_line(fd, &error);
	if (error != 0)
		error_exit("Error\nGNL failure\n", NULL, data);
	while (buffer && buffer[0] == '\n')
	{
		free(buffer);
		buffer = get_next_line(fd, &error);
		if (error != 0)
			error_exit("Error\nGNL failure\n", NULL, data);
	}
	map_handling(buffer, fd, data, lst);
	return ;
}
