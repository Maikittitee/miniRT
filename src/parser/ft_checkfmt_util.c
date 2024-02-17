/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfmt_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:43:26 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/17 21:44:43 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	ft_check_notnbr_point(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_notnbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_count_char(char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
}

int	ft_check_clr(char *str)
{
	char	**sp_clr;

	sp_clr = ft_split(str, ',');
	// ft_print2d(sp_clr);
	if (ft_cnt2d(sp_clr) != 3)
		return (-1);
	if (ft_notnbr(sp_clr[0]) == -1)
		return (-1);
	if (ft_notnbr(sp_clr[1]) == -1)
		return (-1);
	if (ft_notnbr(sp_clr[2]) == -1)
		return (-1);
	ft_doublefree(sp_clr);
	return (0);
}
