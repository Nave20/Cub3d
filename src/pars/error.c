/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:27:54 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/07 17:50:07 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	free_map_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	error_exit(char *err_msg, t_list *lst, t_data *data)
{
	if (lst)
		free_lst(lst);
	if (data)
	{
		if (data->map)
			free_map_tab(data->map);
		free(data);
	}
	perror(err_msg);
	exit(errno);
}

void	free_lst(t_list *lst)
{
	t_list	*ptr;

	while (lst->next)
	{
		ptr = lst->next;
		if (lst->content)
		{
			free(lst->content);
			lst->content = NULL;
		}
		free(lst);
		lst = ptr;
	}
	if (lst->content)
	{
		free(lst->content);
		lst->content = NULL;
	}
	free(lst);
}
