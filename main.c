/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:54:50 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/04 12:47:01 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_print_array(char **arr, int m)
{
	while (arr != NULL && *arr != NULL && arr[m])
	{
		ft_putstr(arr[m++]);
		ft_putchar('\n');
	}
}

int				main(int argc, char **argv)
{
	int			p[8];
	char		*str;
	t_tetr_list	*l;
	char		**arr;

	l = NULL;
	arr = NULL;
	ft_bzero(p, 32);
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(1);
	}
	str = ft_record_str(argv[1], p);
	ft_check_tetr(str, p, 0, 0);
	ft_create_tetr_list(str, &l, 0, 0);
	if (l == NULL)
		ft_quit(str, p);
	if ((arr = ft_solve(&l, p, 0)) == NULL)
		ft_putstr("error\n");
	ft_print_array(arr, 0);
	ft_clean_all(p, arr, &l, str);
}
