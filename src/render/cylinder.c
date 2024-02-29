/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:29:01 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/29 22:23:14 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float	ft_pow2(float a)
{
	return (a * a);
}


float	hit_disk(t_ray ray, t_obj cylin)
{
	t_disk	disk;
	t_vec	hitpoint;
	t_vec	pos;

	disk.denom = vector_dot(ray.dir, cylin.normal_vec);
	if (fabs(disk.denom) < VERYSMALLNUMBER)
		return (-1.0f);
	disk.top = vector_add(cylin.ori, \
	vector_scaler(cylin.h / 2, cylin.normal_vec));
	disk.buttom = vector_add(cylin.ori, \
	vector_scaler(cylin.h / -2, cylin.normal_vec));
	disk.t = vector_dot(vector_sub(disk.top, ray.ori), \
	cylin.normal_vec) / disk.denom;
	disk.tb = vector_dot(vector_sub(disk.buttom, ray.ori), \
	cylin.normal_vec) / disk.denom;
	pos = disk.top;
	if (disk.t < 0.0f || (disk.tb > 0.00f && disk.tb < disk.t))
	{
		disk.t = disk.tb;
		pos = disk.buttom;
	}
	hitpoint = vector_add(ray.ori, vector_scaler(disk.t, ray.dir));
	if (disk.t < 0.0f || vector_size(vector_sub(hitpoint, pos)) > cylin.d / 2)
		return (-1.0f);
	return (disk.t);
}

float	hit_cylinder(t_ray ray, t_obj cylin)
{
	t_quad	quad;
	t_vec	oc;
	float	m;

	cylin.normal_vec = vector_norm(cylin.normal_vec);
	oc = vector_sub(ray.ori, cylin.ori);
	quad.a = vector_dot(ray.dir, ray.dir) \
	- ft_pow2(vector_dot(ray.dir, cylin.normal_vec));
	quad.b = 2 * (vector_dot(ray.dir, oc) \
	- vector_dot(ray.dir, cylin.normal_vec) * vector_dot(oc, cylin.normal_vec));
	quad.c = vector_dot(oc, oc) - ft_pow2(vector_dot(oc, cylin.normal_vec)) \
	- ft_pow2(cylin.d / 2.0f);
	quad.discriminant = quad.b * quad.b - 4 * quad.a * quad.c;
	if (quad.discriminant < 0.0f)
		return (-1.0f);
	quad.t = ((-1 * quad.b - sqrt(quad.discriminant)) / (2 * quad.a));
	m = vector_dot(ray.dir, cylin.normal_vec) * quad.t \
	+ vector_dot(oc, cylin.normal_vec);
	if (fabsf(m) > cylin.h / 2)
		return (-1.0f);
	return (quad.t);
}

t_bool	is_cylin_disk(t_ray ray, t_obj obj)
{
	float	t;

	t = hit_cylinder(ray, obj);
	printf("t: %f\n", t);
	if (t > 0.0f)
		return (False);
	t = hit_disk(ray, obj);
	if (t > 0.0f)
	{
		printf("hit_disk\n");
		return (True);
	}
	return (False);
}
