/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cx_input_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:16:22 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/30 15:28:04 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pswlink	*dataprep(int ac, char **av)
{
	char		**data;
	t_pswlink	*a;

	data = handling_data(ac, av);
	if (!data)
	{
		ft_putendl_fd("Error", 2);
		exit(errno);
	}
	if (cx_valid(data) == 0)
	{
		ft_free_p2p_char(data);
		return (NULL);
	}
	a = psw_atolink(data);
	if (!a)
	{
		ft_free_p2p_char(data);
		return (NULL);
	}
	ft_free_p2p_char(data);
	return (a);
}

char	**handling_data(int ac, char **av)
{
	char	**data;

	if (ac == 2)
		data = ft_split(av[1], ' ');
	else
		data = psw_multicase(av);
	return (data);
}

// if not OK return NULL
// digit + -
// cx if there any sign after digit // not more than 10
int	cx_valid(char **strptr)
{
	if (psw_digit_pm(strptr) == 0)
		return (0);
	if (psw_cx10aft(strptr) == 0)
		return (0);
	return (1);
}

// cx int max min limit
// cx same num
t_pswlink	*psw_atolink(char **str)
{
	t_pswlink	*a;
	int			*tmp;
	int			count;

	a = NULL;
	tmp = cx_maxmin_int(str, &count);
	if (!tmp)
		return (NULL);
	if (cx_same_num(tmp, count) == 0)
	{
		free(tmp);
		return (NULL);
	}
	a = psw_create_list(tmp, count, a);
	free(tmp);
	if (!a)
		return (NULL);
	add_tagnum(a);
	return (a);
}
