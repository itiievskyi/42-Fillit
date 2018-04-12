/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:08:14 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/04 12:24:38 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_malloc_arr(int i)
{
	int		x;
	int		l;
	char	**arr;

	x = 0;
	if ((arr = (char**)malloc(sizeof(char*) * i + 1)) == NULL)
		return (NULL);
	while (x < i)
	{
		l = 0;
		if ((arr[x] = (char*)malloc(sizeof(char) * i + 1)) == NULL)
		{
			ft_erase_array(arr, x);
			return (NULL);
		}
		while (l < i)
			arr[x][l++] = '.';
		arr[x][i] = '\0';
		x++;
	}
	arr[i] = 0;
	return (arr);
}
