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

static void			erase_map(int z[], t_tetr_list *list, char **arr)
{
	int		x;
	int		l;

	x = 0;
	while(x < z[5])
	{
		l = 0;
		while (l < z[5])
		{
			if (arr[x][l] == list->c)
				arr[x][l] = '.';
			l++;
		}
		x++;
	}
	z[3] = 0;
}

static void			is_fit(int z[], t_tetr_list *l, char **arr)
{
	erase_map(z, l, arr);
	if (arr[z[0] + (l->y)[0]][z[1] + (l->x)[0]] == '.' &&
		arr[z[0] + (l->y)[1]][z[1] + (l->x)[1]] == '.' &&
		arr[z[0] + (l->y)[2]][z[1] + (l->x)[2]] == '.' &&
		arr[z[0] + (l->y)[3]][z[1] + (l->x)[3]] == '.')
	{
		arr[z[0] + (l->y)[0]][z[1] + (l->x)[0]] = l->c;
		arr[z[0] + (l->y)[1]][z[1] + (l->x)[1]] = l->c;
		arr[z[0] + (l->y)[2]][z[1] + (l->x)[2]] = l->c;
		arr[z[0] + (l->y)[3]][z[1] + (l->x)[3]] = l->c;
		z[3] = 1;
	}
	else
		z[3] = -1;
}


static void			place_tetr(int z[], t_tetr_list *list, char **arr)
{
	int v[2];
	ft_bzero(v, 8);
	z[0] = 0;
	z[1] = 0;
	z[3] = 0;

	while (z[3] != 1 && z[1] < z[5] && z[0] < z[5] && z[4] != 1)
	{
		z[0] = v[0];
		z[1] = v[1];
		while (z[3] != 1 && z[1] < z[5] && z[0] < z[5])
		{
			is_fit(z, list, arr);
			z[1]++;
			if(z[1] >= z[5])
			{
				z[1] = 0;
				z[0]++;
				if (z[0] >= z[5] || z[1] >= z[5])
					break;
			}
		}
		v[0] = z[0];
		v[1] = z[1];
		if (list->next != NULL && z[3] == 1)
			place_tetr(z, list->next, arr);
		if (z[6] - 1 == (int)((list)->c - 'A') && z[3] == 1)
			z[4] = 1;
	}
}

char				**ft_solve(t_tetr_list **list, int p[], int a)
{
	int			z[10];
	char		**arr;
	t_tetr_list	*l;

	ft_bzero(z, 40);
	while (z[4] == 0 && z[5] < 12)
	{
		l = *list;
		ft_bzero(z, 40);
		z[5] = p[6] + a;
		z[6] = p[4];
		arr = ft_malloc_arr(z[5]);
		place_tetr(z, l, arr);
		a++;
	}
	return (arr);
}
