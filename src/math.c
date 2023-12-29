/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 03:10:52 by ktunchar          #+#    #+#             */
/*   Updated: 2023/12/30 01:51:07 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vec vector_add(t_vec a, t_vec b)
{
	t_vec ret;

	ret.i = a.i + b.i;
	ret.j = a.j + b.j;
	ret.k = a.k + b.k;
	
	return (ret);
}

t_vec vector_sub(t_vec a, t_vec b)
{
	t_vec ret;

	ret.i = a.i - b.i;
	ret.j = a.j - b.j;
	ret.k = a.k - b.k;
	
	return (ret);
}

float vector_dot(t_vec a, t_vec b)
{
	float result;

	result = a.i * b.i + a.j * b.j + a.k * b.k;

	return (result);
}

t_vec vector_cross(t_vec a, t_vec b)
{
	t_vec ret;

	ret.i = +(a.j * b.k - a.k * b.j);
	ret.j = -(a.i * b.k - a.k * b.i);
	ret.k = +(a.i * b.j -  a.j * b.i);

	return (ret);
}

float vector_size(t_vec u)
{
	return (sqrt(u.i * u.i + u.j * u.j + u.k * u.k ));
}

t_vec vector_norm(t_vec u)
{
	t_vec ret;
	float size;

	size = vector_size(u);
	ret.i = u.i / size;
	ret.j = u.j / size;
	ret.k = u.k / size;
	
	return (ret);	
}

t_vec c_vec(float c, t_vec u)
{
	return ((t_vec){c * u.i, c * u.j, c * u.k});
}

