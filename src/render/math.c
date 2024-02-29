/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:29:12 by ktunchar          #+#    #+#             */
/*   Updated: 2024/03/01 01:34:53 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec	vector_add(t_vec a, t_vec b)
{
	t_vec	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_vec	vector_sub(t_vec a, t_vec b)
{
	t_vec	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

float	vector_dot(t_vec a, t_vec b)
{
	float	result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;
	return (result);
}

t_vec	vector_cross(t_vec a, t_vec b)
{
	t_vec	ret;

	ret.x = +(a.y * b.z - a.z * b.y);
	ret.y = -(a.x * b.z - a.z * b.x);
	ret.z = +(a.x * b.y - a.y * b.x);
	return (ret);
}

float	vector_size(t_vec u)
{
	return (sqrt(u.x * u.x + u.y * u.y + u.z * u.z));
}
