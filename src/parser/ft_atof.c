/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:22:23 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/20 23:19:23 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float ft_power(int index)
{
	float	res;
	int		i;

	i = 0;
	res = 1;
	while (i < index)
	{
		res = res * 0.1;
		i++;
	}
	return (res);
}

float	ft_float(char *str)
{
	int		i;
	int		j;
	float	res;

	i = 1;
	j = 1;
	res = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			res = res + (ft_power(j) * (str[i] - '0'));
		j++;
		i++;
	}
	return (res);
}

float	ft_atof(char *str)
{
	int		i;
	int		j;
	float	res;
	float	sym;

	i = 0;
	res = 0;
	sym = 1;
	if (*str == '-')
	{
		sym = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (10 * res) + (str[i] - '0');
		str++;
	}
	j = 1;
	if (*str == '.')
		res = res + ft_float(str);
	return (res * sym);
}
