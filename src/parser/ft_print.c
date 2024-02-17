/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:54:25 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/17 15:55:50 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	ft_printhw(void)
{
	printf("Hello world\n");
}
void	ft_print2d(char **str)
{
	int	i;

	i = -1;
	while(str[++i])
		printf("sp2d : %s\n", str[i]);
}