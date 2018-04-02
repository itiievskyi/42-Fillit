/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:54:50 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/29 12:55:17 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int			p[10];
	char		*str;
	t_tetr_list	*l;

	l = NULL;
	str = record_str(argv[1], p);
	check_tetr(str, p, 0, 0);
	ft_create_tetr_list(str, &l, 0, 0);
	printf("Symbols = %d\tLength = %zu\tTetriminos = %d\tMin map size = %d\n", \
			p[3], ft_strlen(str), p[4], p[6]);
	printf("%s\n", str);
	if (argc > 1 && argv[1])
		ft_putstr("hello\n\n");
	t_tetr_list	*z = l;
	while(z)
	{
		printf("%c\n", (char)z->c);
		printf("%d\t%d\t%d\t%d\n", (int)(z->y)[0], (int)(z->y)[1], (int)(z->y)[2], (int)(z->y)[3]);
		printf("%d\t%d\t%d\t%d\n\n", (int)(z->x)[0], (int)(z->x)[1], (int)(z->x)[2], (int)(z->x)[3]);
		z = z->next;
	}
	return (0);
}
