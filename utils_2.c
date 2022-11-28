/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:33:42 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/29 04:02:36 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cx_maxmin_int(char **str, int *count)
{
	long	tmp;
	int		*ret;
	int		i;

	*count = count_element_p2p(str);
	ret = (int *)malloc(sizeof(int) * (*count));
	if (!ret)
		return (0);
	i = 0;
	while (str[i])
	{
		tmp = ft_atol(str[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
		{
			free(ret);
			return (0);
		}
		else
			ret[i] = (int)tmp;
		i++;
	}
	return (ret);
}

int	cx_same_num(int *arrnum, int count)
{
	int	i;
	int	j;

	if (count == 1)
		return (1);
	i = 0;
	while (i < (count - 1))
	{
		j = i + 1;
		while (j < count)
		{
			if (arrnum[i] == arrnum[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_pswlink	*psw_create_list(int *arrnum, int count, t_pswlink *a)
{
	t_pswlink	*now;
	t_pswlink	*new;
	int			i;

	i = 0;
	a = (t_pswlink *)malloc(sizeof(t_pswlink));
	if (!a)
		return (NULL);
	a->num = arrnum[i];
	now = a;
	i++;
	while (i < count)
	{
		new = (t_pswlink *)malloc(sizeof(t_pswlink));
		if (!new)
			break ;
		new->num = arrnum[i];
		now->next = new;
		now = now->next;
		new = NULL;
		i++;
	}
	if (psw_count_list(a) != count)
		a = psw_freelist(a);
	return (a);
}

int	psw_count_list(t_pswlink *row)
{
	int	i;

	i = 0;
	while (row != NULL)
	{
		i++;
		row = row->next;
	}
	return (i);
}

t_pswlink	*psw_freelist(t_pswlink *row)
{
	t_pswlink	*nxt;

	nxt = row->next;
	while (row)
	{
		free(row);
		row = nxt;
		if (nxt != NULL)
			nxt = nxt->next;
	}
	return (NULL);
}
