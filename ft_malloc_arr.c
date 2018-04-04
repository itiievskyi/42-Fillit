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

#include "libft.h"
#include "fillit.h"

char	**ft_malloc_arr(int i)
{
	int		x;
	int		l;
	char	**arr;

	x = 0;
	arr = (char**)malloc(sizeof(char*) * i + 1);
	while (x < i)
	{
		l = 0;
		arr[x] = (char*)malloc(sizeof(char) * i + 1);
		while (l < i)
			arr[x][l++] = '.';
		arr[x][i] = '\0';
		x++;
	}
	arr[i] = 0;
	return (arr);
}
