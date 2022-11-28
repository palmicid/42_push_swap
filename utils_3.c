/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:26:41 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/29 04:01:43 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_tagnum(t_pswlink *a)
{
	int	i;

	i = 1;
	init_zero(a);
	while (cx_tag_zero(a))
	{
		tag_putin(a, i);
		i++;
	}
}

void	init_zero(t_pswlink *a)
{
	while (a)
	{
		a->tag = 0;
		a = a->next;
	}
}

// find 0 = 1, no zero = 0
int	cx_tag_zero(t_pswlink *a)
{
	while (a)
	{
		if (a->tag == 0)
			return (1);
		a = a->next;
	}
	return (0);
}

void	tag_putin(t_pswlink *a, int i)
{
	int			min;
	t_pswlink	*ptr;

	ptr = a;
	while (ptr)
	{
		if (ptr->tag == 0)
		{
			min = ptr->num;
			break ;
		}
		ptr = ptr->next;
	}
	min = find_min(ptr);
	while (a)
	{
		if (a->num == min)
		{
			a->tag = i;
			break ;
		}
		a = a->next;
	}
}

int	find_min(t_pswlink *ptr)
{
	int	min;

	min = INT_MAX;
	while (ptr)
	{
		if (ptr->tag == 0 && ptr->num < min)
			min = ptr->num;
		ptr = ptr->next;
	}
	return (min);
}
