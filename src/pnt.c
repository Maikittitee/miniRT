/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:07:23 by ktunchar          #+#    #+#             */
/*   Updated: 2023/12/19 16:02:57 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vec xy_to_vec(int x, int y)
{
	t_vec ret;

	ret.i = x;
	ret.j = y;
	ret.k = 0;

	return (ret);
	
}