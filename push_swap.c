/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:24:14 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/17 15:24:31 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stackhead	*box = NULL;
	
	if (ac == 1 || (ac == 2 && (ft_strlen(av[1]) == 0)))
		exit(EXIT_SUCCESS);
	box = (t_stackhead *)malloc(sizeof(t_stackhead));
	box->a = dataprep(ac, av);
	if (!box->a)
	{
		// for testrun
		ft_putendl_fd("TEST RUN - ERROR", 2);
		ft_putendl_fd("Error", 2);
		psw_freelist(box->a);
		free(box);
		exit(EXIT_FAILURE);
	}
	// for test run
	ft_putendl_fd("TEST RUN - 02", 2);
	box->a = psw_freelist(box->a);
	free(box);

	// add to list (dataprep)
	// sort

	// free(box);

	
	return (0);	
}
