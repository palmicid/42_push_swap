/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:47:37 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/30 01:25:05 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pswlink	*opr_swap(t_pswlink *swap)
{
	t_pswlink	*tmp;

	tmp = swap->next;
	swap->next = tmp->next;
	tmp->next = swap;
	swap = tmp;
	return (swap);
}

t_pswlink	*opr_rotate(t_pswlink *rot)
{
	t_pswlink	*tmp;
	t_pswlink	*last;

	tmp = rot;
	rot = rot->next;
	tmp->next = NULL;
	last = rot;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = tmp;
	return (rot);
}

t_pswlink	*opr_rev_rotate(t_pswlink *rrot)
{
	t_pswlink	*tmp;
	t_pswlink	*ptr;

	ptr = rrot;
	while (ptr->next->next != NULL)
	{
		ptr = ptr->next;
	}
	tmp = rrot;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = rrot;
	ptr->next = NULL;
	rrot = tmp;
	return (rrot);
}
