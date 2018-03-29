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

void	check_char(char **arr, int p[], char ch)
{
	if (ch != '.' && ch != '#' && ch != '\n')
		quit(arr, p);
	if ((ch == '.' || ch == '#') && p[2] > 3)
		quit(arr, p);
	if (ch == '\n' && p[2] != 4 && (p[1] % 4 != 0 || p[1] == 0))
		quit(arr, p);
	if (ch == '\n' && p[2] != 0 && (p[1] % 4 == 0 || p[1] != 0))
		quit(arr, p);
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

	fd = open(arg, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
	{
		check_char(arr, p, ch);

	}
}
