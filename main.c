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

#include "libft.h"
#include "fillit.h"

int				main(int argc, char **argv)
{
	int			p[15];
	char		*str;
	t_tetr_list	*l;
	char		**arr;
	int			m;

	m = 0;
	l = NULL;
	arr = NULL;
	ft_bzero(p, 60);
	if (argc != 2)
		ft_putstr("error\n");
	str = ft_record_str(argv[1], p);
	ft_check_tetr(str, p, 0, 0);
	ft_create_tetr_list(str, &l, 0, 0);
	arr = ft_solve(&l, p, 0);
	while (arr[m])
	{
		ft_putstr(arr[m]);
		ft_putchar('\n');
		m++;
	}
	return (0);
}
