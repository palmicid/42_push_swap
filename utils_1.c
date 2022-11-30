/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:15:50 by pruangde          #+#    #+#             */
/*   Updated: 2022/11/30 15:40:12 by pruangde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**psw_multicase(char **av)
{
	int		i;
	char	*store;
	char	**ret;

	store = (char *)malloc(sizeof(char) * 1);
	if (!store)
		return (NULL);
	store[0] = '\0';
	i = 1;
	while (av[i])
	{
		store = psw_strjoin(store, av[i]);
		i++;
	}
	ret = ft_split(store, ' ');
	free(store);
	return (ret);
}

char	*psw_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = ' ';
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	free(s1);
	return (new);
}

int	psw_digit_pm(char **strptr)
{
	int	i;
	int	j;

	i = 0;
	while (strptr[i])
	{
		j = 0;
		while (strptr[i][j])
		{
			if (sp_digit_pm(strptr[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// cx + - not more than 1
// cx digit not more than 10 MAX_INT
// cx nothing else follow it must be \0
// if all OK return 1, if not return 0
int	psw_cx10aft(char **strptr)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	while (strptr[++i])
	{
		j = 0;
		while (strptr[i][j])
		{
			c = 0;
			if (strptr[i][j] == '-' || strptr[i][j] == '+')
				j++;
			while (ft_isdigit(strptr[i][j]))
			{
				c++;
				j++;
			}
			if (c > 10 || c == 0)
				return (0);
			if (strptr[i][j] != 0)
				return (0);
		}
	}
	return (1);
}
