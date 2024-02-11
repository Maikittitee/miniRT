/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:32:19 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/11 19:33:10 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int		ft_atorgb(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	// printf("str[i] : %s\n", str);
	// exit(0);
	while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		printf("symbol\n");
		return(-1);
	}
	while(str[i])
	{
		// printf("str[i] : %d\n", str[i]);
		if ((str[i] < '0' && str[i] > '9'))
		{
			printf("wrong character\n");
			return(-1);
		}
		if (str[i] != '\n')
			res = (res * 10) + str[i] - '0';
		// printf("str[%d]  : %d\n",str[i],  res);
		if (res > 255)
		{
			printf("more than 255\n");
			return(-1); // fixed
		}
		i++;
	}
	return(res);
}

float	ft_power(float nbr, int pow)
{
	int		i;
	float	res;

	i = 0;
	res = 0;
	if (pow == 1)
		return(nbr);
	while (i < pow)
	{
		res = nbr * nbr;
		i++;
	}
	return(res);
}


float	ft_atof(char *str)
{
	int		i;
	float	dec;
	int		sym;
	float		point;
	int	round;

	i = 0;
	dec = 0;
	sym = 1;
	point = 0;
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
		if(str[i] == '.')
		{
			i++;
			round = 1;
			while(str[i])
			{
				point = (point + (ft_power(0.1, round) * (str[i] - '0')));
				round+=1;
				i++;
				if (str[i] == '\0')
					return((point + dec) * sym);
			}
		}
		dec = (dec * 10) + str[i] - '0';
		i++;
	}
	return(dec * sym);

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