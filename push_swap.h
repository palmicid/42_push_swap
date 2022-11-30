/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:24:40 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/30 14:49:16 by pruangde         ###   ########.fr       */
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
void		sorting(t_stackhead *box);

// cx_input_1
t_pswlink	*dataprep(int ac, char **av);
char		**handling_data(int ac, char **av);
int			cx_valid(char **strptr);
t_pswlink	*psw_atoink(char **strptr);

// operation_1
void		sorting_hall(t_stackhead *box, char *inst);
void		gate_swap(t_stackhead *box, char *inst);
void		gate_opr_push(t_stackhead *box, char *inst);
void		gate_rotate(t_stackhead *box, char *inst);
void		gate_rev_rotate(t_stackhead *box, char *inst);

// operation_2
t_pswlink	*opr_swap(t_pswlink *swap);
t_pswlink	*opr_rotate(t_pswlink *rot);
t_pswlink	*opr_rev_rotate(t_pswlink *rrot);

// sort_1
int			cx_complete(t_pswlink *a);
void		to_radix(t_stackhead *box, int count);
void		sub_radix(t_stackhead *box, int count, int shift);
void		sort_two(t_stackhead *box);
void		sort_three(t_stackhead *box);

// sort_2
void		sort_four(t_stackhead *box);
void		sort_five(t_stackhead *box);
void		sort_five_2(t_stackhead *box);
int			spcx_comp345(t_pswlink *a);

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
void		add_tagnum(t_pswlink *a);
void		init_zero(t_pswlink *a);
int			cx_tag_zero(t_pswlink *a);
void		tag_putin(t_pswlink *a, int i);
int			find_min(t_pswlink *ptr);

#endif
