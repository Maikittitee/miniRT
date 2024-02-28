/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:29:01 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/28 20:42:08 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// t_vec rotateX(t_vec before, float theta)
// {
// 	t_vec after;

// 	after.x = before.x;
// 	after.y = 
float ft_pow2(float a)
{
	return (a*a);
}
float	hit_disk(t_ray ray, t_obj cylin)
{
	float denom;
	t_vec top;
	t_vec buttom;
	float tb;
	float t;
	t_vec pos;

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
	t_vec hitpoint = vector_add(ray.ori, vector_scaler(t, ray.dir));
	if (vector_size(vector_sub(hitpoint, pos)) > cylin.d / 2)
		return (-1.0f);
	return (t);
}

float	hit_cylinder(t_ray ray, t_obj cylin)
{
	float t;
	cylin.normal_vec = vector_norm(cylin.normal_vec);
	// t_vec tmp;
	
	
	t_vec oc = vector_sub(ray.ori, cylin.ori);
	float a = vector_dot(ray.dir, ray.dir) - ft_pow2(vector_dot(ray.dir, cylin.normal_vec));
	float b = 2 * (vector_dot(ray.dir, oc) - vector_dot(ray.dir, cylin.normal_vec) * vector_dot(oc, cylin.normal_vec));
	float c = vector_dot(oc, oc) - ft_pow2(vector_dot(oc, cylin.normal_vec)) - ft_pow2(cylin.d / 2.0f);
	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0f)
		return (-1.0f);
	
	// printf("discriminant: %f\n", discriminant);
	t = ((-1 * b - sqrt(discriminant)) / (2 * a));

		
	float m = vector_dot(ray.dir, cylin.normal_vec) * t + vector_dot(oc, cylin.normal_vec);
	if (fabsf(m) > cylin.h / 2)
		return (-1.0f);
	return (t);

	
	
}

t_bool is_cylin_disk(t_ray ray, t_obj obj)
{
	float t;

	t = hit_cylinder(ray, obj);
	if (t > 0.0f)
		return (False);
	t = hit_disk(ray, obj);
	if (t > 0.0f)
		return (True);
	return (False);
}

