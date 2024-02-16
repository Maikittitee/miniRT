/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 23:23:39 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/16 00:53:26 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float ft_power(char c, int round)
{
	int		i;
	float	res;

	i = 0;
	res = 1;
	if(!c)
		return(0);
	while (i < round)
	{
		res = res * 0.1;
		i++;
	}
	return(res * (c - '0'));
}

int	ft_cntkey(char *str, char c)
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
	return(cnt);
}
int	ft_check_all_alpha(char *str)
{
	int	i;

	i = 0;
	// printf("check all alpha\n");
	while(str[i])
	{
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			return(-1);
		i++;
	}
	return(0);
}
int	ft_check_frm(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '.')
		return(-1);
	if (ft_check_all_alpha(str) == -1 || ft_cntkey(str, '.') != 1)
		return(-1);
	return(0);
}

float ft_float(char *str)
{
	float res;
	int		j;

	res = 0;
	if (*str == '.')
	{
		str++;
		j = 1;
		while (*str)
		{
			if (*str >= '0' && *str <= '9')
				res = res + ft_power(*str, j);
			j++;
			str++;
		}
	}
	return(res);
}
float ft_atof(char *str)
{
	float	res;
	float	sym;

	res = 0;
	sym = 1;
	if (ft_check_frm(str) == -1)
		return(0);
	if (*str == '-' || *str == '+')
	{
		if(*str == '-')
			sym = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (10 * res) + (*str - '0');
		str++;
	}
	res = res + ft_float(str);
	return(res * sym);
}
// int main(void)
// {
// 	int	state;

// 	state = 0;

// 	printf("ft_power : %f\n", ft_atof(".1", &state));
// 	printf("state : %d\n", state);
// }