/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atorgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:01:11 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/21 22:42:52 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

unsigned char	ft_atorgb(char *str, int *state)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] != '\n')
		{
			res = (10 * res) + (str[i] - '0');
		}
		if (res > 255)
		{
			*state = -1;
			return (0);
		}
		i++;
	}
	return (res);
}
