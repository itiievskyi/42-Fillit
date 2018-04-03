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

static t_tetr_list	*get_tetr_elem(t_tetr_list **list, int n, int i)
{
	t_tetr_list	*l;

	l = *list;
	while (i < n)
	{
		l = (*list)->next;
		i++;
	}
	return (l);
}

static void			is_fit(int z[], t_tetr_list *l, char **arr)
{
	if (arr[z[1] + (l->x)[0]][z[0] + (l->y)[0]] == '.' &&
		arr[z[1] + (l->x)[1]][z[0] + (l->y)[1]] == '.' &&
		arr[z[1] + (l->x)[2]][z[0] + (l->y)[2]] == '.' &&
		arr[z[1] + (l->x)[3]][z[0] + (l->y)[3]] == '.')
	{
		arr[z[1] + (l->x)[0]][z[0] + (l->y)[0]] = l->c;
		arr[z[1] + (l->x)[1]][z[0] + (l->y)[1]] = l->c;
		arr[z[1] + (l->x)[2]][z[0] + (l->y)[2]] = l->c;
		arr[z[1] + (l->x)[3]][z[0] + (l->y)[3]] = l->c;
		z[3] = 1;
	}
	else
		z[3] = -1;
}

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
}

static void			place_tetr(int z[], t_tetr_list *l, char **arr)
{
	while (z[3] != 1 && z[0] < z[5] && z[1] < z[5])
	{
		is_fit(z, l, arr);
		if (z[3] == -1 && z[1] < z[5] && z[0] < z[5])
		{
			z[1]++;
			if(z[1] >= z[5])
			{
				z[1] = 0;
				z[0]++;
			}
		}
	}
}

char				**ft_solve(t_tetr_list **list, int p[], int a)
{
	int			z[10];
	char		**arr;
	t_tetr_list	*l;

	ft_bzero(z, 40);
	while (z[4] == 0 && z[2] <= p[4])
	{
		ft_bzero(z, 40);
		z[5] = p[6] + a;
		arr = ft_malloc_arr(z[5]);
		while (z[2] < p[4] && z[3] != 1)
		{
			z[0] = 0;
			z[1] = 0;
			l = get_tetr_elem(list, z[2], 0);
			erase_map(z, l, arr);
			place_tetr(z, l, arr);
			if (z[3] == 1)
			{
				z[3] = 0;
				z[2]++;
			}
			else
			{
				z[2]--;
			}
		}
		if (z[2] == p[4] && z[3] == 0)
			z[4] = 1;
		a++;
	}
	return (arr);
}
