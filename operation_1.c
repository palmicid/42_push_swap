/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:43:01 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/30 01:24:21 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_hall(t_stackhead *box, char *inst)
{
	if (ft_strlen(inst) == 3)
		gate_rev_rotate(box, inst);
	else
	{
		if (inst[0] == 's')
			gate_swap(box, inst);
		else if (inst[0] == 'p')
			gate_opr_push(box, inst);
		else if (inst[0] == 'r')
			gate_rotate(box, inst);
	}
}

void	gate_swap(t_stackhead *box, char *inst)
{
	if (inst[1] == 'a')
		box->a = opr_swap(box->a);
	else if (inst[1] == 'b')
		box->b = opr_swap(box->b);
	else if (inst[1] == 's')
	{
		box->a = opr_swap(box->a);
		box->b = opr_swap(box->b);
	}
	ft_putendl_fd(inst, 1);
}

void	gate_opr_push(t_stackhead *box, char *inst)
{
	t_pswlink	*tmp;

	if (inst[1] == 'a')
	{
		tmp = box->b;
		box->b = box->b->next;
		tmp->next = box->a;
		box->a = tmp;
	}
	else if (inst[1] == 'b')
	{
		tmp = box->a;
		box->a = box->a->next;
		tmp->next = box->b;
		box->b = tmp;
	}
	ft_putendl_fd(inst, 1);
}

void	gate_rotate(t_stackhead *box, char *inst)
{
	if (inst[1] == 'a')
		box->a = opr_rotate(box->a);
	else if (inst[1] == 'b')
		box->b = opr_rotate(box->b);
	else if (inst[1] == 'r')
	{
		box->a = opr_rotate(box->a);
		box->b = opr_rotate(box->b);
	}
	ft_putendl_fd(inst, 1);
}

void	gate_rev_rotate(t_stackhead *box, char *inst)
{
	if (inst[2] == 'a')
		box->a = opr_rev_rotate(box->a);
	else if (inst[2] == 'b')
		box->b = opr_rev_rotate(box->b);
	else if (inst[2] == 'r')
	{
		box->a = opr_rev_rotate(box->a);
		box->b = opr_rev_rotate(box->b);
	}
	ft_putendl_fd(inst, 1);
}
