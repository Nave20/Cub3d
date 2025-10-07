/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaysant <lpaysant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:38:50 by lpaysant          #+#    #+#             */
/*   Updated: 2025/10/07 12:02:51 by lpaysant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	print_lst(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while(ptr != NULL)
	{
		printf("%s", (char *)ptr->content);
		ptr = ptr->next;
	}
	return ;
}
