/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tetr_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:23:58 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/04 12:43:36 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			ft_list_zero(int x[], int y[], t_tetr_list **l)
{
	ft_bzero(x, 16);
	ft_bzero(y, 16);
	*l = NULL;
}

static void			check_arrs(int x[], int y[], int a, int b)
{
	while (x[0] > 0 && x[1] > 0 && x[2] > 0 && x[3] > 0)
	{
		x[0] -= a;
		x[1] -= a;
		x[2] -= a;
		x[3] -= a;
	}
	while (y[0] > 0 && y[1] > 0 && y[2] > 0 && y[3] > 0)
	{
		y[0] -= b;
		y[1] -= b;
		y[2] -= b;
		y[3] -= b;
	}
}

static t_tetr_list	*ft_create_elem(int x1[], int y1[], int ch)
{
	t_tetr_list	*list;

	if ((list = malloc(sizeof(t_tetr_list))) == NULL)
		return (NULL);
	(list->x)[0] = x1[0];
	(list->y)[0] = y1[0];
	(list->x)[1] = x1[1];
	(list->y)[1] = y1[1];
	(list->x)[2] = x1[2];
	(list->y)[2] = y1[2];
	(list->x)[3] = x1[3];
	(list->y)[3] = y1[3];
	list->c = 'A' + ch;
	list->next = NULL;
	return (list);
}

static int			ft_list_push_back(t_tetr_list **l, int x[], int y[], int c)
{
	t_tetr_list *temp;

	temp = *l;
	if (temp != NULL)
	{
		while (temp->next)
			temp = temp->next;
		if ((temp->next = ft_create_elem(x, y, c)) == NULL)
		{
			*l = NULL;
			return (-1);
		}
	}
	else
	{
		if ((*l = ft_create_elem(x, y, c)) == NULL)
		{
			*l = NULL;
			return (-1);
		}
	}
	return (1);
}

void				ft_create_tetr_list(char *s, t_tetr_list **l, int i, int a)
{
	int x[4];
	int y[4];
	int h;

	ft_list_zero(x, y, l);
	while (s[i] != '\0')
	{
		a = 0;
		h = 0;
		while (h != 4)
		{
			if (s[i++] == '#')
			{
				x[h] = a % 5;
				y[h++] = a / 5;
			}
			a++;
		}
		check_arrs(x, y, 1, 1);
		if ((ft_list_push_back(l, x, y, i / 21)) == -1)
			break ;
		while (i % 21 && s[i] != '\0')
			i++;
	}
}
