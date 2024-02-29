/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kztunchar <kztunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 03:10:52 by ztunchar          #+#    #+#             */
/*   Updated: 2024/01/29 00:23:52 by kztunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec vector_add(t_vec a, t_vec b)
{
	t_vec ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;

	return (ret);
}

t_vec vector_sub(t_vec a, t_vec b)
{
	t_vec ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;

	return (ret);
}

float vector_dot(t_vec a, t_vec b)
{
	float result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;

	return (result);
}

t_vec vector_cross(t_vec a, t_vec b)
{
	t_vec ret;

	ret.x = +(a.y * b.z - a.z * b.y);
	ret.y = -(a.x * b.z - a.z * b.x);
	ret.z = +(a.x * b.y -  a.y * b.x);

	return (ret);
}

float vector_size(t_vec u)
{
	return (sqrt(u.x * u.x + u.y * u.y + u.z * u.z ));
}

t_vec vector_norm(t_vec u)
{
	t_vec ret;
	float size;

	size = vector_size(u);
	ret.x = u.x / size;
	ret.y = u.y / size;
	ret.z = u.z / size;

	return (ret);
}

t_vec vector_div(t_vec u, t_vec v)
{
	return ((t_vec){u.x/v.x, u.y/v.y, u.z/v.z});
}

t_vec vector_scaler(float c, t_vec u)
{
	return ((t_vec){c * u.x, c * u.y, c * u.z});
}
