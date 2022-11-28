/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:24:40 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/17 15:25:24 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "libft/libft.h"
# include <errno.h>
# include <sys/errno.h>
# include <limits.h>

typedef struct s_pswlink
{
	int					num;
	int					tag;
	struct s_pswlink	*next;
}			t_pswlink;

typedef struct s_stackhead
{
	struct s_pswlink	*a;
	struct s_pswlink	*b;
}						t_stackhead;

// push_swap

// operator_1

// cx_input_1
t_pswlink	*dataprep(int ac, char **av);
char		**handling_data(int ac, char **av, char **data);
int			cx_valid(char **strptr);
t_pswlink	*psw_atoink(char **strptr);

// utils_1
char		**psw_multicase(char **av);
char		*psw_strjoin(char *s1, char *s2);
int			psw_digit_pm(char **strptr);
int			psw_cx10aft(char **strptr);
t_pswlink	*psw_atolink(char **str);

// utils_2
int			*cx_maxmin_int(char **str, int *count);
int			cx_same_num(int *arrnum, int count);
t_pswlink	*psw_create_list(int *arrnum, int count, t_pswlink *a);
int			psw_count_list(t_pswlink *row);
t_pswlink	*psw_freelist(t_pswlink *row);

// utils_3

#endif

// prep
//	add to list and add tag number
// sort
// 	with binary tag num
