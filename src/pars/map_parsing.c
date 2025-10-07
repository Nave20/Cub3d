/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:07:44 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/07 13:21:52 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

bool	is_good_char(char c)
{
	if (c && c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W'
		&& c != 'O')
		return (0);
	else
		return (1);
}

bool	is_map_line(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return(0);
	while (str[i])
	{
		if (is_good_char(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	cpy_map_to_lst(t_list *lst, char *buffer, int fd, int error)
{
	t_list	*ptr;

	lst = NULL;
	while (is_map_line(buffer))
	{
		ptr = ft_lstnew(buffer);
		if (!ptr)
			error_exit("Error\nft_lstnew failure\n");
		ft_lstadd_back(&lst, ptr);
		buffer = get_next_line(fd, &error);
		if (error != 0)
			error_exit("Error\nGNL failure\n");
	}
	print_lst(lst);
	free_lst(lst);
	return ;
}

void	add_fist_border_to_tab(t_list *lst, t_data *data)
{
	int	i;

	i = 0;
	data->map[0] = ft_calloc(data->cols + 3, sizeof(char));
	if(!data->map[0])
		error_exit("Error\nMalloc failure\n");
	while(i < data->cols + 3)
	{
		data->map[0][i] = 'X';
		i++;
	}
}

void	find_cols_nb_map(t_data *data, t_list *lst)
{
	t_list *ptr;
	int	col;

	ptr = lst;
	data->cols = 0;
	while(ptr)
	{
		col = ft_strlen(ptr->content);
		if(col > data->cols)
			data->cols = col;
		ptr = ptr->next;
	}
}

void	cpy_lst_to_tab(t_list *lst, t_data *data)
{
	t_list	*ptr;
	int	i;
	int	j;

	data->lines = ft_lstsize(lst);
	i = 1;
	j = 0;
	ptr = lst;
	data->map = ft_calloc(data->lines + 3, sizeof(char *));
	add_fist_border_to_tab(lst, data);
	while(ptr != NULL)
	{
		while()
	}
}

void	find_map(int fd, t_data *data)
{
	char	*buffer;
	t_list	*lst;
	int		error;

	(void)data;
	lst = NULL;
	buffer = get_next_line(fd, &error);
	if (error != 0)
		error_exit("Error\nGNL failure\n");
	while (buffer != NULL)
	{
		if (is_map_line(buffer))
		{
			cpy_map_to_lst(lst, buffer, fd, error);
			cpy_lst_to_tab(lst, data);
			return;
		}
		buffer = get_next_line(fd, &error);
		if (error != 0)
			error_exit("Error\nGNL failure\n");
	}
	error_exit("Error\nThere are no characters requested for the map(1, 0, W, S, N, O)\n ");
	return ;
}

// void	get_map(int fd, t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	find_map(fd, data);
// }
