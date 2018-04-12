/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:33:48 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/04 12:46:35 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			erase_map(int size, t_tetr_list *list, char **arr)
{
	int		x;
	int		l;

	x = 0;
	while (x < size)
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

static int			ft_find_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i);
}

static int			is_fit(int x1, int y1, t_tetr_list *l, char **arr)
{
	int				size;

	size = ft_find_size(arr);
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
		return (0);
}

static int			place_tetr(int size, t_tetr_list *list, char **arr)
{
	int x;
	int y;

	y = 0;
	if (list == NULL)
		return (1);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (is_fit(x, y, list, arr))
			{
				if (place_tetr(size, list->next, arr))
					return (1);
				else
					erase_map(size, list, arr);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char				**ft_solve(t_tetr_list **list, int p[], int a)
{
	char		**arr;
	int			solve;
	int			size;

	size = a + p[6];
	solve = 0;
	while (solve != 1 && size < 15)
	{
		if (size > p[6])
			ft_erase_array(arr, size - 1);
		if ((arr = ft_malloc_arr(size)) == NULL)
			return (NULL);
		solve = place_tetr(size, *list, arr);
		size++;
	}
	p[6] = size;
	return (arr);
}
