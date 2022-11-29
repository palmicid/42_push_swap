/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:24:14 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/29 20:51:29 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//-------======== TEST=======----------
void	test_print(t_stackhead *box)
{
	t_pswlink	*ptr;

	ptr = box->a;
	printf("A = ");
	while (ptr)
	{
		printf(" %d ", ptr->tag);
		ptr = ptr->next;
	}
	ft_putchar_fd('\n', 1);

	ptr = box->b;
	printf("B = ");
	while (ptr)
	{
		printf(" %d ", ptr->tag);
		ptr = ptr->next;
	}
	ft_putchar_fd('\n', 1);
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
	// sort
	// sorting(box);
	// TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST
	sorting_hall(box, "pb");
	sorting_hall(box, "pb");
	sorting_hall(box, "pb");
	sorting_hall(box, "pb");
	sorting_hall(box, "rrr");
	// sorting_hall(box, "rra");
	// sorting_hall(box, "rrr");
	test_print(box);
	// TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST
	// finish every thing
	box->a = psw_freelist(box->a);
	box->b = psw_freelist(box->b);
	free(box);
	return (0);	
}
