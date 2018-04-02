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

void	count_tetr(char *arg, char **arr, int p[])
{
	int		fd;
	char	ch;

	fd = open(arg, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
		check_char(arr, p, ch);
	if (p[3] < 20)
		quit(arr, p);
	if (p[1] > 128 || p[1] < 4 || (p[1] + 1) % 5 != 0)
		quit(arr, p);
	if (((p[1] + 1) != 5 * p[4]) || ((p[3] + 1) != p[4] * 21))
		quit(arr, p);
	close(fd);
}

void	check_char(char **arr, int p[], char ch)
{
	if (p[1] > 128 || p[2] > 4)
		quit(arr, p);
	if (ch != '.' && ch != '#' && ch != '\n')
		quit(arr, p);
	p[3]++;
	if (ch == '#')
		p[5]++;
	if (ch == '\n')
	{
		if ((++p[1] + 1) % 5 == 0)
		{
			p[4]++;
			if (p[5] != 4)
				quit(arr, p);
			p[5] = 0;
		}
	}
	if ((ch == '.' || ch == '#') && p[2] > 3)
		quit(arr, p);
	if (ch != '\n' && p[3] % 21 == 0 && p[1] != 0)
		quit(arr, p);
	if (ch == '\n')
		p[2] = 0;
	else
		p[2]++;
}

void	record_str(char *arg, char **arr, int p[])
{
	int		fd;
	char	ch;

	count_tetr(arg, arr, p);
	fd = open(arg, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
		ft_putchar(ch);
	close(fd);
}
