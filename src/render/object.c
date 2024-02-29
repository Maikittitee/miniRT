/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:30:36 by ktunchar          #+#    #+#             */
/*   Updated: 2024/03/01 01:18:14 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

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

t_bool can_go_light(t_ray ray, t_data data, float t_to_obj)
{
	float t;

	if (t_to_obj < 0.0f)
		return (True);
	t = vector_size(vector_sub(data.light.ori, ray.ori));
	if (t < t_to_obj)
		return (True);
	return (False);
}

t_bool	is_hit_object(t_ray ray, unsigned int except, t_obj *obj, t_data data)
{
	unsigned int	i;

	i = 0;
	while (i < data.nobj)
	{
		if (i != except && obj[i].type == SPHERE \
		&& !can_go_light(ray, data, hit_sphere(ray, obj[i])))
			return (True);
		if (i != except && obj[i].type == PLANE \
		&&  !can_go_light(ray, data, hit_plane(ray, obj[i])))
			return (True);
		if (i != except && obj[i].type == CYLIN \
		&& (!can_go_light(ray, data, hit_cylinder(ray, obj[i]))|| \
		!can_go_light(ray, data, (hit_disk(ray, obj[i])))))
			return (True);
		i++;
	}
	return (False);
}

t_hit	apply_hit(int target_index, float closet_t)
{
	t_hit	hit;

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

t_hit	hit_object(t_ray ray, t_obj *obj, t_data data)
{
	unsigned int	i;
	float			min_t;
	int				tar_i;

	i = 0;
	min_t = 99999999.0f;
	tar_i = -1;
	while (i < data.nobj)
	{
		obj[i].normal_vec = vector_norm(obj[i].normal_vec);
		if (obj[i].type == SPHERE)
			min_t = get_closet_t(hit_sphere(ray, obj[i]), min_t, &tar_i, i);
		else if (obj[i].type == PLANE)
			min_t = get_closet_t(hit_plane(ray, obj[i]), min_t, &tar_i, i);
		else if (obj[i].type == CYLIN)
		{
			min_t = get_closet_t(hit_cylinder(ray, obj[i]), min_t, &tar_i, i);
			min_t = get_closet_t(hit_disk(ray, obj[i]), min_t, &tar_i, i);
		}
		i++;
	}
	return (apply_hit(tar_i, min_t));
}
