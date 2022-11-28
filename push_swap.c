/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:24:14 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/29 04:17:27 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// sort
	// finish every thing
	box->a = psw_freelist(box->a);
	free(box);
	return (0);	
}
