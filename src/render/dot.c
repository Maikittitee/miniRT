/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:35:34 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/29 21:35:56 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float	activte_dot(float dot, int type, t_bool disk)
{
	if (type == PLANE || disk)
		return (dot);
	return (fmaxf(dot, 0.0f));
}

float	get_dot_product(t_obj obj, t_light light, t_hit hit, t_data data, t_ray ray)
{
	t_bool	disk;
	t_vec	obj_normal_vec;
	t_vec	hitpoint_to_light;
	t_ray	tolight_ray;
	float	dot_p;

	obj_normal_vec = calculate_normal_vector(obj, hit.hitpoint, ray);
	hitpoint_to_light = vector_norm(vector_sub(light.ori, hit.hitpoint));
	dot_p = vector_dot(obj_normal_vec, hitpoint_to_light);
	disk = False;
	if (dot_p < 0.0f && obj.type == PLANE)
	{
		obj_normal_vec = vector_scaler(-1.0f, obj_normal_vec);
		dot_p = vector_dot(obj_normal_vec, hitpoint_to_light);
	}
	if (obj.type == CYLIN && vector_dot(vector_norm(data.cam.direction), vector_norm(obj.normal_vec)) > 0.0f && is_cylin_disk(ray, obj))
	{
		disk = True;
		obj_normal_vec = vector_scaler(-1.0f, obj_normal_vec);
		dot_p = vector_dot(obj_normal_vec, hitpoint_to_light);
	}
	tolight_ray.ori = hit.hitpoint;
	tolight_ray.dir = hitpoint_to_light;
	dot_p = activte_dot(dot_p, obj.type, disk);
	if (is_hit_object(tolight_ray, hit.index, data.obj, data))
		return (0.0f);
	return (dot_p);
}