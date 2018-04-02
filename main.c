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
	int		p[10];
	char	*str;

	str = record_str(argv[1], p);
	check_tetr(str, p, 0, 0);
	printf("Symbols = %d\tLength = %zu\tTetriminos = %d\tMin map size = %d\n", \
			p[3], ft_strlen(str), p[4], p[6]);
	printf("%s\n", str);
	if (argc > 1 && argv[1])
		ft_putstr("hello\n");
	return (0);
}
