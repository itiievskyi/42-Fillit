/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:33:48 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/03 10:33:50 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

static void			erase_map(int size, t_tetr_list *list, char **arr)
{
	int		x;
	int		l;

	x = 0;
	while(x < size)
	{
		l = 0;
		while (l < size)
		{
			if (arr[x][l] == list->c)
				arr[x][l] = '.';
			l++;
		}
		x++;
	}
}

static int			is_fit(int i, t_tetr_list *l, char **arr, int size)
{
	int	x1;
	int	y1;

	x1 = i % 4;
	y1 = i / 4;
	erase_map(size, l, arr);
	if ((l->y)[0] + y1 >= size || (l->y)[1] + y1 >= size ||
		(l->y)[2] + y1 >= size || (l->y)[3] + y1 >= size ||
		(l->x)[0] + x1 >= size || (l->x)[1] + x1 >= size ||
		(l->x)[2] + x1 >= size || (l->x)[3] + x1 >= size)
		return (0);
	if (arr[y1 + (l->y)[0]][x1 + (l->x)[0]] == '.' &&
		arr[y1 + (l->y)[1]][x1 + (l->x)[1]] == '.' &&
		arr[y1 + (l->y)[2]][x1 + (l->x)[2]] == '.' &&
		arr[y1 + (l->y)[3]][x1 + (l->x)[3]] == '.')
	{
		arr[y1 + (l->y)[0]][x1 + (l->x)[0]] = l->c;
		arr[y1 + (l->y)[1]][x1 + (l->x)[1]] = l->c;
		arr[y1 + (l->y)[2]][x1 + (l->x)[2]] = l->c;
		arr[y1 + (l->y)[3]][x1 + (l->x)[3]] = l->c;
		return (1);
	}
	else
		printf("%c = WRONG\n", l->c);
		return (0);
}


static int			place_tetr(int size, t_tetr_list *list, char **arr)
{
	int i;
	int solve;

	i = 0;
	solve = 0;
	while ((i < size * size) && solve == 0)
	{
		if (is_fit(i, list, arr, size) == 1 && list->c == 'B')
			return (1);
		if (is_fit(i, list, arr, size) == 1 && solve == 0)
		{
			if (list->next != NULL)
				solve = place_tetr(size, list->next, arr);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

char				**ft_solve(t_tetr_list **list, int p[], int a)
{
	char		**arr;
	int 		solve;
	int			size;

	size = a + p[6];
	solve = 0;
//	while (solve != 1 && size < 12)
//	{
		arr = ft_malloc_arr(size);
		solve = place_tetr(size, *list, arr);
		size++;
//	}
	return (arr);
}
