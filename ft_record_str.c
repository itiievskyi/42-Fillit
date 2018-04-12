/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:17:56 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/04 14:17:58 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_count_chars(char *arg, int p[])
{
	int		fd;
	char	ch;
	int		c;

	c = 0;
	fd = open(arg, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
	{
		c++;
		if (c > 545)
		{
			close(fd);
			ft_putstr("error\n");
			ft_bzero(p, 32);
			exit(1);
		}
	}
	close(fd);
	return (c);
}

static int	ft_next_sqrt(int num)
{
	int s;
	int temp;
	int result;

	result = 0;
	temp = num;
	while (result == 0)
	{
		s = 1;
		while (s * s < temp)
		{
			s++;
			if (s * s == temp)
				result = s;
			else
				result = 0;
		}
		temp++;
	}
	return (result);
}

static void	check_char(char *str, int p[], char ch)
{
	if (p[1] > 128 || p[2] > 4)
		ft_quit(str, p);
	if (ch != '.' && ch != '#' && ch != '\n')
		ft_quit(str, p);
	p[3]++;
	if (ch == '#')
		p[5]++;
	if (ch == '\n')
	{
		if ((++p[1] + 1) % 5 == 0)
		{
			p[4]++;
			if (p[5] != 4)
				ft_quit(str, p);
			p[5] = 0;
		}
	}
	if ((ch == '.' || ch == '#') && p[2] > 3)
		ft_quit(str, p);
	if (ch != '\n' && p[3] % 21 == 0 && p[1] != 0)
		ft_quit(str, p);
	if (ch == '\n')
		p[2] = 0;
	else
		p[2]++;
}

char		*ft_record_str(char *arg, int p[])
{
	int		fd;
	char	ch;
	char	*str;
	int		c;

	c = ft_count_chars(arg, p);
	if ((str = (char *)malloc(sizeof(char) * (c + 1))) == NULL)
		ft_quit(str, p);
	fd = open(arg, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
	{
		check_char(str, p, ch);
		str[p[3] - 1] = ch;
	}
	str[p[3]] = '\0';
	if (p[3] < 20)
		ft_quit(str, p);
	if (p[1] > 129 || p[1] < 4 || (p[1] + 1) % 5 != 0)
		ft_quit(str, p);
	if (((p[1] + 1) != 5 * p[4]) || ((p[3] + 1) != p[4] * 21))
		ft_quit(str, p);
	close(fd);
	p[6] = ft_next_sqrt(p[4] * 4);
	return (str);
}
