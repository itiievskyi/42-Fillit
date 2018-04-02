/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_sqrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:24:52 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/02 13:24:55 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_next_sqrt(int num)
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
