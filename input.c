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
	p[6] = ft_next_sqrt(p[4] * 4);
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

void	get_touches(char *s, int p[], int i)
{
	if (s[i - 1] == '#')
		p[7]++;
	if (s[i - 5] == '#')
		p[7]++;
	if (s[i + 1] == '#')
		p[7]++;
	if (s[i + 5] == '#')
		p[7]++;
}

void	check_tetr(char *s, int p[], int i, int x)
{
	while (s[i] != '\0')
	{
		if (i % 21 == 0)
		{
			x = 0;
			p[5] = 0;
			p[7] = 0;
		}
		if (s[i] == '#')
		{
			if (s[i - 1] != '#' && s[i + 1] != '#' && (s[i - 5] != '#'
				|| (s[i - 5] == '#' && x - 5 < 0)) && (s[i + 5] != '#'
				|| (s[i + 5] == '#' && x + 5 > 19)))
				quit(s, p);
			get_touches(s, p, i);
			p[5]++;
			if (p[5] == 4 && p[7] < 6)
				quit(s, p);
		}
		i++;
		x++;
	}
}
