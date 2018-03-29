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

void	count_tetr(char *arg, char **arr, int p[])
{
	int		fd;
	char	ch;

	fd = open(arg, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
	{
		p[3]++;
		if (ch == '\n')
		{
			p[1]++;
			if ((p[1] + 1) % 5 == 0)
				p[4]++;
		}
	}
	if(((p[1] + 1) / 5 != (p[4] + 1)))
		quit(arr, p);
}

void	check_char(char **arr, int p[], char ch)
{
	if (p[1] > 128 || p [2] > 4)
		quit(arr, p);
	if (ch != '.' && ch != '#' && ch != '\n')
		quit(arr, p);
	if ((ch == '.' || ch == '#') && p[2] > 3)
		quit(arr, p);
	if (ch == '\n' && p[2] != 4 && (p[1] % 4 != 0 || p[1] == 0))
		quit(arr, p);
	if (ch == '\n' && p[2] != 0 && (p[1] % 4 == 0 || p[1] != 0))
		quit(arr, p);
	if(ch == '\n')
	{
		p[1]++;
		p[2] = 0;
	}
	else
		p[2]++;
}

void	quit(char **arr, int p[])
{
	ft_putstr("error\n");
	bzero(p, 10);
	free(arr);
	exit(1);
}

void	record_str(char *arg, char **arr, int p[])
{
	int		fd;
	char	ch;
	char	l;

	l = 'A';
	count_tetr(arg, arr, p);
	fd = open(arg, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
	{
		ft_putchar(ch);
		//check_char(arr, p, ch);
	}
}
