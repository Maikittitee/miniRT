/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:35:34 by ktunchar          #+#    #+#             */
/*   Updated: 2024/03/01 01:38:02 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float	activte_dot(float dot, int type, t_bool disk)
{
	if (type == PLANE || disk)
		return (fabsf(dot));
	return (fmaxf(dot, 0.0f));
}

t_dot	get_dot_product(t_obj obj, t_hit hit, t_data data, t_ray r)
{
	t_vec	obj_normal_vec;
	t_vec	hitpoint_to_light;
	t_dot	dot;

	obj_normal_vec = calculate_normal_vector(obj, hit.hitpoint, r);
	hitpoint_to_light = vector_norm(vector_sub(data.light.ori, hit.hitpoint));
	dot.dot = vector_dot(obj_normal_vec, hitpoint_to_light);
	dot.disk = False;
	if (dot.dot < 0.0f && obj.type == PLANE)
	{
		obj_normal_vec = vector_scaler(-1.0f, obj_normal_vec);
		dot.dot = vector_dot(obj_normal_vec, hitpoint_to_light);
	}
	if (obj.type == CYLIN && vector_dot(vector_norm(data.cam.direction), \
	vector_norm(obj.normal_vec)) > 0.0f && is_cylin_disk(r, obj))
	{
		dot.disk = True;
		obj_normal_vec = vector_scaler(-1.0f, obj_normal_vec);
		dot.dot = vector_dot(obj_normal_vec, hitpoint_to_light);
	}
	return (dot);
}

t_vec	calculate_normal_vector(t_obj obj, t_vec hitpoint, t_ray ray)
{
	t_vec	center_to_hp;
	t_vec	proj_vec;

	if (obj.type == SPHERE)
		return (vector_norm(vector_sub(hitpoint, obj.ori)));
	if (obj.type == PLANE)
		return (vector_norm(obj.normal_vec));
	if (obj.type == CYLIN)
	{
		if (is_cylin_disk(ray, obj))
			return (vector_norm(obj.normal_vec));
		center_to_hp = vector_sub(hitpoint, obj.ori);
		proj_vec = vector_scaler(vector_dot(center_to_hp, obj.normal_vec), \
		vector_norm(obj.normal_vec));
		return (vector_norm(vector_sub(center_to_hp, proj_vec)));
	}
	return ((t_vec){0, 0, 0});
}
