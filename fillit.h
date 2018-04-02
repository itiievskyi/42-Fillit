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

void			record_list(char *arg, int p[]);
void			quit(char *str, int p[]);
void			check_char(char *str, int p[], char ch);
char			*record_str(char *arg, int p[]);
int				ft_next_sqrt(int num);
void			check_tetr(char *s, int p[], int i, int x);
void			get_touches(char *s, int p[], int i);

typedef struct	s_tetr_list
{
	int					x[4];
	int					y[4];
	char				c;
	struct s_tetr_list	*next;
}				t_tetr_list;

#endif
