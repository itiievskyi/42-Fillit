/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:52:10 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/29 12:53:42 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void	record_list(char *arg, int p[]);
void	quit(char *str, int p[]);
void	check_char(char *str, int p[], char ch);
char	*record_str(char *arg, int p[]);
int		ft_next_sqrt(int num);

#endif
