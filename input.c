/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:54:38 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/29 17:56:59 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

char	*record_str(char *arg, int p[])
{
	int		fd;
	char	ch;
	char	*str;

	str = (char *)malloc(sizeof(char));
	fd = open(arg, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
	{
		check_char(str, p, ch);
		str[p[3] - 1] = (char)malloc(sizeof(char));
		str[p[3] - 1] = ch;
	}
	str[p[3]] = (char)malloc(sizeof(char));
	str[p[3]] = 0;
	if (p[3] < 20)
		quit(str, p);
	if (p[1] > 128 || p[1] < 4 || (p[1] + 1) % 5 != 0)
		quit(str, p);
	if (((p[1] + 1) != 5 * p[4]) || ((p[3] + 1) != p[4] * 21))
		quit(str, p);
	close(fd);
	p[7] = ft_next_sqrt(p[4] * 4);
	return (str);
}

void	check_char(char *str, int p[], char ch)
{
	if (p[1] > 128 || p[2] > 4)
		quit(str, p);
	if (ch != '.' && ch != '#' && ch != '\n')
		quit(str, p);
	p[3]++;
	if (ch == '#')
		p[5]++;
	if (ch == '\n')
	{
		if ((++p[1] + 1) % 5 == 0)
		{
			p[4]++;
			if (p[5] != 4)
				quit(str, p);
			p[5] = 0;
		}
	}
	if ((ch == '.' || ch == '#') && p[2] > 3)
		quit(str, p);
	if (ch != '\n' && p[3] % 21 == 0 && p[1] != 0)
		quit(str, p);
	if (ch == '\n')
		p[2] = 0;
	else
		p[2]++;
}

void	record_list(char *arg, int p[])
{
	char	*str;

	str = record_str(arg, p);
	printf("Symbols = %d\tLength = %zu\tTetriminos = %d\tMin map size = %d\n", p[3], ft_strlen(str), p[4], p[7]);
	printf("%s\n", str);
}
