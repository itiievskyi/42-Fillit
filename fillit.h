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
# include "srcl/libft.h"

typedef struct	s_tetr_list
{
	int					x[4];
	int					y[4];
	char				c;
	struct s_tetr_list	*next;
}				t_tetr_list;

void			ft_delete_list(t_tetr_list **alst);
void			ft_record_list(char *arg, int p[]);
void			ft_quit(char *str, int p[]);
void			ft_erase_array(char **arr, int size);
char			*ft_record_str(char *arg, int p[]);
char			*ft_stdin(int p[]);
void			ft_check_tetr(char *s, int p[], int i, int x);
void			ft_create_tetr_list(char *s, t_tetr_list **l, int i, int a);
char			**ft_solve(t_tetr_list **list, int p[], int a);
char			**ft_malloc_arr(int i);
void			ft_clean_all(int p[], char **arr, t_tetr_list **list, char *s);

#endif
