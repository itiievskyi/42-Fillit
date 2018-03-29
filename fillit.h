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

void	record_str(char *arg, char **arr, int p[]);
void	quit(char **arr, int p[]);
void	check_char(char **arr, int p[], char ch);
void	count_tetr(char *arg, char **arr, int p[]);

#endif
