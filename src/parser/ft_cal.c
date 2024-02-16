/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:32:19 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/16 00:47:04 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int		ft_atorgb(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if(str[i] == '+' || str[i] == '-')
		return(-1);
	while(str[i])
	{
		if ((str[i] < '0' && str[i] > '9'))
			return(-1);
		if (str[i] != '\n')
			res = (res * 10) + str[i] - '0';
		if (res > 255)
			return(-1); // fixed
		i++;
	}
	return(res);
}

unsigned char	ft_atousc(char *str)
{
	int				i;
	unsigned char	dec;
	int				sym;

	i = 0;
	dec = 0;
	sym = 1;
	while((str[i] >= 9 && str[i] <= 13)|| str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sym = -1;
		i++;
	}
	while((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		dec = (dec * 10) + str[i] - '0';
		i++;
	}
	return(dec * sym);
}
int	ft_cnt2d(char **str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}
// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	// printf("res---- : %f\n", ft_atof(av[1]));
// 	printf("res---- : %u\n", ft_atousc(av[1]));
// }