/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:07:44 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/15 15:41:41 by lpaysant         ###   ########.fr       */
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

void	cpy_lst_to_tab(t_list *lst, t_all *all)
{
	t_list	*ptr;
	int		i;
	int		j;

	find_cols_nb_map(all->data, lst);
	all->data->lines = ft_lstsize(lst);
	i = 1;
	j = 0;
	ptr = lst;
	all->data->map = ft_calloc(all->data->lines + 3, sizeof(char *));
	if (!all->data->map)
		error_exit("Error\nMalloc failure", all, lst);
	add_fist_border_to_tab(lst, all);
	while (ptr != NULL)
	{
		all->data->map[i] = ft_calloc(all->data->cols + 3, sizeof(char));
		if (!all->data->map[i])
			error_exit("Error\nMalloc failure", all, lst);
		all->data->map[i][j++] = ' ';
		fill_line(all->data, ptr->content, i, j);
		i++;
		j = 0;
		ptr = ptr->next;
	}
	add_last_border_to_tab(lst, all, i);
}

t_list	*cpy_map_to_lst(t_all *all, char *buffer, int fd, int error)
{
	t_list	*ptr;
	t_list	*lst;

	lst = NULL;
	while (is_map_line(buffer))
	{
		ptr = ft_lstnew(buffer);
		if (!ptr)
			error_exit("Error\nft_lstnew failure\n", all, lst);
		ft_lstadd_back(&lst, ptr);
		buffer = get_next_line(fd, &error);
		if (error != 0)
			error_exit("Error\nGNL failure\n", all, lst);
	}
	if (buffer)
		check_file_ending(fd, all, buffer, lst);
	return (lst);
}

void	map_handling(char *buffer, int fd, t_all *all, t_list *lst)
{
	int	error;

	error = 0;
	if (buffer && is_map_line(buffer))
	{
		lst = cpy_map_to_lst(all, buffer, fd, error);
		cpy_lst_to_tab(lst, all);
		free_lst(lst);
		print_map(all->data->map);
		return ;
	}
	else
	{
		printf("%s\n", buffer);
		free(buffer);
		error_exit("Error\nThere are no requested characters for the map\n ",
			all, lst);
	}
}

void	find_map(int fd, t_all *all)
{
	char	*buffer;
	t_list	*lst;
	int		error;

	lst = NULL;
	buffer = get_next_line(fd, &error);
	if (error != 0)
		error_exit("Error\nGNL failure\n", all, lst);
	while (buffer && buffer[0] == '\n')
	{
		free(buffer);
		buffer = get_next_line(fd, &error);
		if (error != 0)
			error_exit("Error\nGNL failure\n", all, lst);
	}
	map_handling(buffer, fd, all, lst);
	return ;
}
