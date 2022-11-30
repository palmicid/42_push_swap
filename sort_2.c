/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:55:42 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/30 14:33:00 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stackhead *box)
{
	while ((cx_complete(box->a) == 0))
	{
		if (box->a->tag > box->a->next->tag)
		{
			if (!(box->a->tag == 4 && box->a->next->tag == 1))
				sorting_hall(box, "sa");
		}
		sorting_hall(box, "ra");
	}
}

void	sort_five(t_stackhead *box)
{
	while ((cx_complete(box->a) == 0))
	{
		if (box->a->tag == 1 || box->a->tag == 2)
		{	
			sorting_hall(box, "pb");
			if (box->a->tag == 1 || box->a->tag == 2)
				sorting_hall(box, "pb");
		}
		if (psw_count_list(box->a) == 3)
		{
			sort_five_2(box);
			if (box->b->tag == 1)
				sorting_hall(box, "sb");
			sorting_hall(box, "pa");
			sorting_hall(box, "pa");
		}
		else
			sorting_hall(box, "ra");
	}
}

// cx b 1 2
void	sort_five_2(t_stackhead *box)
{
	while (spcx_comp345(box->a) == 0)
	{
		if (box->a->tag == 3)
		{
			sorting_hall(box, "rra");
			sorting_hall(box, "sa");
		}
		else if (box->a->tag == 4)
		{
			if (box->a->next->tag == 3)
				sorting_hall(box, "sa");
			else
				sorting_hall(box, "rra");
		}
		else if (box->a->tag == 5)
		{
			if (box->a->next->tag == 3)
				sorting_hall(box, "ra");
			else
				sorting_hall(box, "sa");
		}
	}
}

// same as cp_complete but start at 3 for sub-sort 5
int	spcx_comp345(t_pswlink *a)
{
	int	i;

	i = 3;
	while (a)
	{
		if (a->tag != i)
			return (0);
		i++;
		a = a->next;
	}
	return (1);
}
