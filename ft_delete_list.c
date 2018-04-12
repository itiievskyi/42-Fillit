/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:19:39 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/04 15:19:41 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_delete_list(t_tetr_list **alst)
{
	t_tetr_list	*list;
	t_tetr_list	*fwd;

	list = *alst;
	while (list)
	{
		fwd = list->next;
		ft_bzero(list->x, 16);
		ft_bzero(list->y, 16);
		list->c = '\0';
		free(list);
		list = fwd;
	}
	*alst = NULL;
}
