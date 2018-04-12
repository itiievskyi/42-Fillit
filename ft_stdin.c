/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:48:58 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/12 14:49:00 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

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

char		*ft_stdin(int p[])
{
	char	*str;
	char	ch;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * 545);
	while (read(0, &ch, 1) > 0)
	{
		check_char(str, p, ch);
		str[i] = ch;
		i++;
	}
	str[i] = '\0';
	if (p[3] < 20)
		ft_quit(str, p);
	if (p[1] > 129 || p[1] < 4 || (p[1] + 1) % 5 != 0)
		ft_quit(str, p);
	if (((p[1] + 1) != 5 * p[4]) || ((p[3] + 1) != p[4] * 21))
		ft_quit(str, p);
	p[6] = ft_next_sqrt(p[4] * 4);
	return (str);
}
