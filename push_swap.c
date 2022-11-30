/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:24:14 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/30 14:47:30 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stackhead *box)
{
	int	count;

	count = psw_count_list(box->a);
	if (count == 1)
		return ;
	else if (count == 2)
		sort_two(box);
	else if (count == 3)
		sort_three(box);
	else if (count == 4)
		sort_four(box);
	else if (count == 5)
		sort_five(box);
	else
		to_radix(box, count);
}

int	main(int ac, char **av)
{
	t_stackhead	*box;

	box = NULL;
	if (ac == 1 || (ac == 2 && (ft_strlen(av[1]) == 0)))
		exit(EXIT_SUCCESS);
	box = (t_stackhead *)malloc(sizeof(t_stackhead));
	box->a = dataprep(ac, av);
	if (!box->a)
	{
		ft_putendl_fd("Error", 2);
		free(box);
		exit(EXIT_FAILURE);
	}
	box->b = NULL;
	sorting(box);
	box->a = psw_freelist(box->a);
	free(box);
	exit(EXIT_SUCCESS);
}
