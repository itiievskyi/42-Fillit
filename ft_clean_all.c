/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:43:27 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/04 15:43:30 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clean_all(int p[], char **arr, t_tetr_list **list, char *s)
{
	if (arr != NULL && *arr != NULL)
		ft_erase_array(arr, p[6] - 1);
	ft_delete_list(list);
	free(s);
	ft_bzero(p, 32);
}
