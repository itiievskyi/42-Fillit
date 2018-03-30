/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:16:58 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/30 11:17:00 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	quit(char **arr, int p[])
{
	ft_putstr("error\n");
	bzero(p, 10);
	free(arr);
	exit(1);
}