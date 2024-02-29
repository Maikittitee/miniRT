/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:29:01 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/29 17:26:10 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float	ft_pow2(float a)
{
	return (a * a);
}
float	hit_disk(t_ray ray, t_obj cylin)
{
	float	denom;
	t_vec	top;
	t_vec	buttom;
	float	tb;
	float	t;
	t_vec	hitpoint;
	t_vec	pos;

	denom = vector_dot(ray.dir, cylin.normal_vec);
	if (fabs(denom) < VERYSMALLNUMBER)
		return (-1.0f);
	top = vector_add(cylin.ori, vector_scaler(cylin.h / 2, cylin.normal_vec));
	buttom = vector_add(cylin.ori, vector_scaler(cylin.h / -2, cylin.normal_vec));
	t = vector_dot(vector_sub(top, ray.ori), cylin.normal_vec) / denom;
	tb = vector_dot(vector_sub(buttom, ray.ori), cylin.normal_vec) / denom;
	pos = top;
	if (t < 0.0f || (tb > 0.00f && tb < t))
	{
		t = tb;
		pos = buttom;
	}
	if (t < 0.0f)
		return (-1.0f);
	hitpoint = vector_add(ray.ori, vector_scaler(t, ray.dir));
	if (vector_size(vector_sub(hitpoint, pos)) > cylin.d / 2)
		return (-1.0f);
	return (t);
}

float	hit_cylinder(t_ray ray, t_obj cylin)
{
	float	t;
	float	a;
	float	b;
	float	c;
	float	discriminant;
	t_vec	oc;

	cylin.normal_vec = vector_norm(cylin.normal_vec);
	oc = vector_sub(ray.ori, cylin.ori);
	a = vector_dot(ray.dir, ray.dir) - ft_pow2(vector_dot(ray.dir, cylin.normal_vec));
	b = 2 * (vector_dot(ray.dir, oc) - vector_dot(ray.dir, cylin.normal_vec) * vector_dot(oc, cylin.normal_vec));
	c = vector_dot(oc, oc) - ft_pow2(vector_dot(oc, cylin.normal_vec)) - ft_pow2(cylin.d / 2.0f);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0f)
		return (-1.0f);
	t = ((-1 * b - sqrt(discriminant)) / (2 * a));
	a = vector_dot(ray.dir, cylin.normal_vec) * t + vector_dot(oc, cylin.normal_vec);
	if (fabsf(a) > cylin.h / 2)
		return (-1.0f);
	return (t);
}

t_bool	is_cylin_disk(t_ray ray, t_obj obj)
{
	float	t;

	t = hit_cylinder(ray, obj);
	if (t > 0.0f)
		return (False);
	t = hit_disk(ray, obj);
	if (t > 0.0f)
		return (True);
	return (False);
}
