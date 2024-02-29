/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:33:15 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/29 21:34:15 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec	vector_norm(t_vec u)
{
	t_vec	ret;
	float	size;

	size = vector_size(u);
	if (size == 1.0f)
		return (u);
	ret.x = u.x / size;
	ret.y = u.y / size;
	ret.z = u.z / size;
	return (ret);
}

t_vec	vector_div(t_vec u, t_vec v)
{
	return ((t_vec){u.x / v.x, u.y / v.y, u.z / v.z});
}

t_vec	vector_scaler(float c, t_vec u)
{
	return ((t_vec){c * u.x, c * u.y, c * u.z});
}
