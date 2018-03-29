/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:54:38 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/29 15:54:40 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	quit(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	record_str(char **arr, int p[])
{
	fd = open(arg, O_RDONLY);
	while (read(fd, &ch, 1) > 0 && y < res[7])
	{
		if (p[0] == 1)
			exit();
		if (ch != '.' || ch != '#' || ch != '\n')
			p[0] = 1;
	}
}
