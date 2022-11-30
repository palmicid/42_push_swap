/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:20:05 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/30 01:31:04 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cx_complete(t_pswlink *a)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->tag != i)
			return (0);
		i++;
		a = a->next;
	}
	return (1);
}

void	to_radix(t_stackhead *box, int count)
{
	int	shift;

	shift = 0;
	while (cx_complete(box->a) == 0)
	{
		sub_radix(box, count, shift);
		shift++;
	}
}

void	sub_radix(t_stackhead *box, int count, int shift)
{
	while (count)
	{
		if (((box->a->tag >> shift) % 2) == 0)
			sorting_hall(box, "pb");
		else
			sorting_hall(box, "ra");
		count--;
	}
	count = psw_count_list(box->b);
	while (count)
	{
		sorting_hall(box, "pa");
		count--;
	}
}

void	sort_two(t_stackhead *box)
{
	if (cx_complete(box->a) == 0)
		sorting_hall(box, "sa");
}

void	sort_three(t_stackhead *box)
{
	while (cx_complete(box->a) == 0)
	{
		if (box->a->tag == 1)
		{
			sorting_hall(box, "rra");
			sorting_hall(box, "sa");
		}
		else if (box->a->tag == 2)
		{
			if (box->a->next->tag == 1)
				sorting_hall(box, "sa");
			else
				sorting_hall(box, "rra");
		}
		else if (box->a->tag == 3)
		{
			if (box->a->next->tag == 1)
				sorting_hall(box, "ra");
			else
				sorting_hall(box, "sa");
		}
	}
}
