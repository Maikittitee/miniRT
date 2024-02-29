/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:30:36 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/29 17:37:14 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float	activte_dot(float dot, int type, t_bool disk)
{
	if (type == PLANE || disk)
		return (dot);
	return (fmaxf(dot, 0.0f));
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
		proj_vec = vector_scaler(vector_dot(center_to_hp, obj.normal_vec), vector_norm(obj.normal_vec));
		return (vector_norm(vector_sub(center_to_hp, proj_vec)));
	}
	return ((t_vec){0, 0, 0});
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

float	get_closet_t(float new_t, float old_t, int *target_index, int index)
{
	if (new_t < 0.0f)
		return (old_t);
	if (new_t > old_t)
	{
		if (*target_index == -1)
			*target_index = index;
		return (old_t);
	}
	*target_index = index;
	return (new_t);
}

t_bool	is_hit_object(t_ray ray, unsigned int except, t_obj *obj, t_data data)
{
	unsigned int i;

	i = 0;
	while (i < data.nobj)
	{
		if (i != except && obj[i].type == SPHERE && hit_sphere(ray, obj[i]) > 0.0f)
			return (True);
		if (i != except && obj[i].type == PLANE && hit_plane(ray, obj[i]) > 0.0f)
			return (True);
		else if (i != except && obj[i].type == CYLIN && hit_cylinder(ray, obj[i]) > 0.0f)
			return (True);
		i++;
	}
	return (False);
}

t_hit	hit_object(t_ray ray, t_obj *obj, t_data data)
{
	unsigned int	i;
	float			closet_t;
	int				target_index;
	t_hit			hit;
	
	i = 0;
	closet_t = VERYBIGNUMBER;
	target_index = -1;
	while (i < data.nobj)
	{
		obj[i].normal_vec = vector_norm(obj[i].normal_vec);
		if (obj[i].type == SPHERE)
			closet_t = get_closet_t(hit_sphere(ray, obj[i]), closet_t, &target_index, i);
		else if (obj[i].type == PLANE)
			closet_t = get_closet_t(hit_plane(ray, obj[i]), closet_t, &target_index, i);
		else if (obj[i].type == CYLIN)
		{
			closet_t = get_closet_t(hit_cylinder(ray, obj[i]), closet_t, &target_index, i);
			closet_t = get_closet_t(hit_disk(ray, obj[i]), closet_t, &target_index, i);
		}
		i++;
	}
	if (target_index == -1 || closet_t < 0.0f)
	{
		hit.is_hit = False;
		hit.index = -1;
		hit.t = -1.0f;
	}
	else
	{
		hit.is_hit = True;
		hit.index = target_index;
		hit.t = closet_t;
	}
	return (hit);
}
